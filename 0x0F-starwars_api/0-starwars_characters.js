#!/usr/bin/node
const request = require('request');

function doGet (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (error, res, body) {
      if (!error && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
}

async function getFilms () {
  if (process.argv[2] == null) { return; }

  const url = 'https://swapi-api.hbtn.io/api';
  const film = await doGet(url + '/films/' + process.argv[2]);
  const characters = JSON.parse(film).characters;

  for (let i = 0; i < characters.length; i++) {
    let people = await doGet(characters[i]);
    people = JSON.parse(people);
    console.log(people.name);
  }
}

getFilms();
