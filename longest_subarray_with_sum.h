#ifndef LONGEST_SUBARRAY_WITH_SUM_H
#define LONGEST_SUBARRAY_WITH_SUM_H

/* [AE][H]
 *
 * GIVEN: non-empty array of non-negative integers
 *        non-negative integer representing a target sum.
 *
 * FIND:  the longest subarray where the values collectively sum up
 *        to the target sum.
 *
 * RETURN: array containing the starting index and ending index of this
 *         subarray, both inclusive.
 *         if there is no subarray that sums up to the target sum, the
 *         function should return an empty array.
*/

#include <vector>

std::vector<int> longestSubarrayWithSum(std::vector<int> array, int targetSum);

namespace Test {

void longestSubarrayWithSum_Naive();
void longestSubarrayWithSum_SlidingWindow();

} // namespace Test

#endif // LONGEST_SUBARRAY_WITH_SUM_H
