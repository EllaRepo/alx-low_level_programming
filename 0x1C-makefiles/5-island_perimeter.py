#!/usr/bin/python3
"""This module defines a function that returns the perimeter of
   the island described in grid
"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid
    Args:
        grid: lists of list
    """
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j]:
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:
                    perimeter -= 2
    return perimeter
