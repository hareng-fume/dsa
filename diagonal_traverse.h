#ifndef DIAGONAL_TRAVERSE_H
#define DIAGONAL_TRAVERSE_H

/* GIVEN:
 *      2D integer array nums.
 *      
 * RETURN:
 *      All elements of nums in diagonal order as shown in the below images.
 *      
 * EXAMPLE:
 * **************************************************************************
 *      Input: nums = [[1,2,3],
 *                     [4,5,6],
 *                     [7,8,9]]
 *      Output: [1,4,2,7,5,3,8,6,9] <= [1], [4,2], [7,5,3], [8,6], [9]
 *      
 * **************************************************************************
 *      Input: nums = [[1,2,3,4,5],
 *                     [6,7],
 *                     [8],
 *                     [9,10,11],
 *                     [12,13,14,15,16]]
 *                     
 *      Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16] <= [1], [6,2], [8,7,3], [9,4], [12,10,5], [13,11], [14], [15], [16]
 * **************************************************************************
*/

#include <vector>

std::vector<int> findDiagonalOrder_bfs(std::vector<std::vector<int>> &nums);
std::vector<int> findDiagonalOrder_hashmap(std::vector<std::vector<int>> &nums);

namespace Test {
enum class Approach { BFS, HashMap };
void findDiagonalOrder(const Approach i_approach);
} // namespace Test

#endif // DIAGONAL_TRAVERSE_H
