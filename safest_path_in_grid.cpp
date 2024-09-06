#include "safest_path_in_grid.h"
#include "utils.h"

#include <array>
#include <iostream>
#include <queue>

/*
    grid[r][c] = 1 => thief.
    grid[r][c] = 0 => empty.
*/

namespace Impl {

bool _safenessFactorIsValid(const std::vector<std::vector<int>> &grid, int safenessFactor)
{
    if (grid[0][0] < safenessFactor || grid[grid.size() - 1][grid[0].size() - 1] < safenessFactor)
        return false;

    // run bfs from (0,0) until (n-1,n-1) is reached or there is no neighbor room which satisfies safenessFactor.

    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid.size(), false));

    std::queue<std::pair<int, int>> roomsToProcess;
    roomsToProcess.push({0, 0});
    visited[0][0] = true;

    const std::array<int, 5> directions{1, 0, -1, 0, 1};
    while (!roomsToProcess.empty()) {
        auto [row, col] = roomsToProcess.front();
        roomsToProcess.pop();

        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return true;

        for (int i = 1; i < directions.size(); ++i) {
            int nRow = row + directions[i - 1];
            int nCol = col + directions[i];

            if (std::min(nRow, nCol) >= 0 && std::max(nRow, nCol) < grid.size()
                && !visited[nRow][nCol] && grid[nRow][nCol] >= safenessFactor) {
                roomsToProcess.push({nRow, nCol});
                visited[nRow][nCol] = true;
            }
        }
    }
    return false;
}

int _maximumSafenessFactor(std::vector<std::vector<int>> &grid)
{
    // find all rooms with a thief.
    std::vector<int> r_thief, c_thief;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                r_thief.push_back(i);
                c_thief.push_back(j);
            }
        }
    }

    // find min distance to a thief for every empty cell, for this
    // compute multisource bfs from every room with a thief.
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

    std::queue<std::pair<int, int>> layer;
    for (int i = 0; i < r_thief.size(); ++i) {
        layer.push({r_thief[i], c_thief[i]});
        visited[r_thief[i]][c_thief[i]] = true;
    }

    const std::array<int, 5> directions{1, 0, -1, 0, 1};
    int distanceToThief = 0;

    while (!layer.empty()) {
        const int _size = layer.size();
        for (int i = 0; i < _size; ++i) {
            auto [r, c] = layer.front();
            layer.pop();
            grid[r][c] = distanceToThief;

            for (int j = 1; j < directions.size(); ++j) {
                int nRow = r + directions[j - 1];
                int nCol = c + directions[j];

                // this works because the grid is of size NxN
                // more conservative condition is nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size()
                if (std::min(nRow, nCol) >= 0 && std::max(nRow, nCol) < grid.size()
                    && !visited[nRow][nCol]) {
                    layer.push({nRow, nCol});
                    visited[nRow][nCol] = true;
                }
            }
        }
        distanceToThief += 1;
    }

    /* now we should try safeness factors to check the reachability from (0,0) to (n-1, n-1).
       min safest factor is 0, the room with a thief itself.
       max safest factor is (distanceToThief-1).
    */

    int minSafenessFactor = 0, maxSafenessFactor = distanceToThief - 1;

    // we can use adapted binary search to find maximum safeness factor
    int resultingSafenessFactor = -1;
    while (minSafenessFactor <= maxSafenessFactor) {
        int currSafenessFactor = (maxSafenessFactor + minSafenessFactor) / 2;
        if (_safenessFactorIsValid(grid, currSafenessFactor)) {
            resultingSafenessFactor = currSafenessFactor;
            minSafenessFactor = currSafenessFactor + 1;
        } else {
            maxSafenessFactor = currSafenessFactor - 1;
        }
    }

    return resultingSafenessFactor;
}
} // namespace Impl

int maximumSafenessFactor(std::vector<std::vector<int>> &grid)
{
    return Impl::_maximumSafenessFactor(grid);
}

namespace Test {
void maximumSafenessFactor()
{
    std::vector<std::vector<int>> grid{{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    Utils::printVectorInt2D(grid);
    const int maxSafenessFactor = Impl::_maximumSafenessFactor(grid);
    Utils::printVectorInt2D(grid);
    std::cout << "max safeness factor: " << maxSafenessFactor << std::endl;
}
} // namespace Test
