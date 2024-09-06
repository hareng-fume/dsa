#ifndef SAFEST_PATH_IN_GRID_H
#define SAFEST_PATH_IN_GRID_H

#include <vector>

/*
    GIVEN: 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

        A cell:
            - [thief]  => grid[r][c] = 1
            - [empty]  => grid[r][c] = 0

        We are initially positioned at cell (0, 0).
        In one move, we can move to any adjacent cell in the grid, including cells containing thieves.
        The 'safeness factor' of a path on the grid is defined as the minimum manhattan distance
        from any cell in the path to any thief in the grid.

    RETURN: the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

    NOTE:
        1) An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
        2) The Manhattan distance between two cells (a, b) and (x, y) is equal to
           |a - x| + |b - y|, where |val| denotes the absolute value of val.

    URL: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
    LEETCODE: #2812 Find the safest path in a grid.
*/

int maximumSafenessFactor(std::vector<std::vector<int>> &grid);

namespace Test {
void maximumSafenessFactor();
}

#endif // SAFEST_PATH_IN_GRID_H
