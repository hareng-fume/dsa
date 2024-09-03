#include "walls_and_gates_multisource_bfs.h"

/* 1) Run DFS from every single room => O((N*M)^2)
 * 2) Loop over the grid to get gate positions, then
 *    loop over all the rooms and compute the distances (mhtn distances)
 *    from a given room to all of the gates, and set the smallest distance
 *    value to the respective room in the grid.
 *    
 *    std::vector<int> r_gate, c_gate;
 *    for(int i = 0; i < grid.size(); ++i) {
 *      for (int j = 0; j < grid[0].size(); ++j) {
 *          if (grid[i][j] == 0) {
 *              r_gate.push_back(i);
 *              c_gate.push_back(j);       
 *          }
 *       }
 *    }
 *
 *    for(int i = 0; i < grid.size(); ++i) {
 *      for (int j = 0; j < grid[0].size(); ++j) {
 *          if (grid[i][j] == INF) {
 *              auto minDistance = INF;
 *              for(int k = 0; k < r_gate.size(); ++k) {
 *                  auto currDistance = abs(i-r_gate[k]) + abs(j-c_gate[k]);
 *                  if (currDistance < minDistance)
 *                      minDistance = currDistance;
 *              }
 *              grid[i][j] = minDistance;
 *          }
 *      }
 *    }
 *
 * 3) Run BFS from every gate simultaneusly, a.k.a. multisource BFS approach.
 *    (implemented below)
 * 
*/

#include <array>
#include <queue>
#include <utility>

// time: O(N*M)
// space: O(N*M)
void wallsAndGates(std::vector<std::vector<int>> &o_grid)
{
    // visited indication
    std::vector<std::vector<bool>> visited(o_grid.size(),
                                           std::vector<bool>(o_grid[0].size(), false));

    std::queue<std::pair<int, int>> layerQueue;
    for (int i = 0; i < o_grid.size(); ++i) {
        for (int j = 0; j < o_grid[0].size(); ++j) {
            if (o_grid[i][j] == 0) {
                layerQueue.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    if (layerQueue.empty())
        return;

    const std::array<int, 5> directions = {1, 0, -1, 0, 1};

    int distance = 0;
    while (!layerQueue.empty()) {
        for (int i = 0; i < layerQueue.size(); ++i) {
            auto [r, c] = layerQueue.front();
            layerQueue.pop();

            o_grid[r][c] = distance;

            for (int j = 1; j < directions.size(); ++j) {
                int newR = r + directions[j - 1];
                int newC = c + directions[j];

                if (newR >= 0 && newR < o_grid.size() && newC >= 0
                    && newC < o_grid[0].size()
                    // all gates have been processed before and marked as visited
                    && !visited[newR][newC]
                    // not an obstacle (not a wall)
                    && o_grid[newR][newC] != -1) {
                    layerQueue.push({newR, newC});
                    visited[newR][newC] = true;
                }
            }
        }
        distance += 1;
    }
}
