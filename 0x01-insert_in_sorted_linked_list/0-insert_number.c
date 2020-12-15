#include "lists.h"

/**
 * *insert_node - insert node with sort condition
 * @head: head node linked list
 * @number: number data of node
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp, *new;


	if (*head == NULL || number < (*head)->n)
	{
		new = malloc(sizeof(listint_t));
		if (new == NULL)
			exit(EXIT_FAILURE);
		new->n = number;
		new->next = *head;
		*head = new;
		return (*head);
	}

	tmp = *head;

	while (tmp->next && tmp->next->n <= number)
		tmp = tmp->next;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->n = number;
	new->next = tmp->next;
	tmp->next = new;

	return (new);
}
