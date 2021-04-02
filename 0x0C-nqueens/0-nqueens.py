#!/usr/bin/python3
"""
The N Queens Problem
Show All possible ways to place N non-attacking Queens on an NxN board
"""

import sys


def cposition(mask, row, col):
    '''Checks position'''
    for c in range(col):
        if mask[c] is row or abs(mask[c] - row) is abs(c - col):
            return False
    return True


def check(mask, col):
    '''Backtracking'''
    n = len(mask)
    if col is n:
        print(str([[c, mask[c]] for c in range(n)]))
        return

    for row in range(n):
        if cposition(mask, row, col):
            mask[col] = row
            check(mask, col + 1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N") or exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number") or exit(1)
    if n < 4:
        print("N must be at least 4") or exit(1)

    mask = [0 for col in range(int(sys.argv[1]))]

    check(mask, 0)
