#ifndef LARGEST_RANGE_H
#define LARGEST_RANGE_H

/* [AE][H] [Largest Range]
 *
 * GIVEN: array of integers, where numbers in it aren't sorted or adjacent.
 *
 * RETURN: array of length 2 representing the largest range of integers contained in the input array.
 *         the first number in the output array should be the first number in the range,
 *         the second number should be the last number in the range.
 *
 * NOTE: a range of numbers is defined as a set of numbers that come right after each other in the set of real integers.
 *       [2,6] represents the range {2,3,4,5,6}, a range of length 5.
 */

#include <vector>

std::vector<int> largestRange(const std::vector<int> &array);

namespace Test {
void largestRange();
}

#endif // LARGEST_RANGE_H
