#ifndef WALLS_AND_GATES_MULTISOURCE_BFS_H
#define WALLS_AND_GATES_MULTISOURCE_BFS_H

/* GIVEN:
 * NxN grid 'rooms' initialized with these three possible values.
 *      -1 a wall or an obstacle.
 *       0 a gate.
 *       INF infinity means an empty room
 *       
 * PROBLEM:
 * fill each empty room with the distance to its nearest gate.
 * if it is impossible to reach a gate, it should be filled with INF.
*/

#include <vector>

void wallsAndGates(std::vector<std::vector<int>> &o_grid);

#endif // WALLS_AND_GATES_MULTISOURCE_BFS_H
