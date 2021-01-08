#!/usr/bin/python3
"""Module to calculate the fewest number of operations needed to result in
  exactly n H characters in the file
  Args:
    n: is a given a number
"""


def minOperationsRecursive(n, h):
    """
      Function Recursive that calculates the fewest
      number of operations needed to
      result in exactly n H characters in the file
      Return: an integer
    """
    if n == h:
        return 0

    if (n >= h * 2):
        val = minOperationsRecursive(n, h * 2)
        if val != -1:
            return val + 2
    if (n >= h + h/2):
        val = minOperationsRecursive(n, h + h/2)
        if val != -1:
            return val + 1

    return -1


def minOperations(n):
    """
      Function that calculates the fewest number of operations needed to
      result in exactly n H characters in the file
      Return: an integer
    """
    if n < 0:
        return 0

    return minOperationsRecursive(n, 1)
