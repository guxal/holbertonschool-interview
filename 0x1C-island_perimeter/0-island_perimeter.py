#!/usr/bin/python3
"""Task 0x1c island_perimeter function """


def island_perimeter(grid):
    island = [i for i in [[v, idx, idx2]
              if v == 1 else None for idx, _ in enumerate(grid)
              for idx2, v in enumerate(_)] if i]

    if (len(island) == 0):
        return 0

    max_h = [v[1] for v in island]
    min_h = [v[1] for v in island]
    max_w = [v[2] for v in island]
    min_w = [v[2] for v in island]

    sum_h = (max(max_h) - min(min_h)) + 1
    sum_w = (max(max_w) - min(min_w)) + 1

    return (sum_h * 2) + (sum_w * 2)
