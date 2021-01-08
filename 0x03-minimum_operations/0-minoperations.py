#!/usr/bin/python3
"""Module to calculate the fewest number of operations needed to result in
  exactly n H characters in the file
  Args:
    n: is a given a number
"""


def minOperations(n):
    """Function that calculates the fewest number of operations needed to
        result in exactly n H characters in the file
        Return: an integer
    """
    result = 0
    i = 2
    aux = n

    if n <= 1:
        return result

    while aux > 1 and i <= n:
        if aux % i == 0:
            aux = aux / i
            result = result + i
        else:
            i = i + 1

    return result
