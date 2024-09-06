#ifndef KTH_SMALLEST_PRIME_FRACTION_H
#define KTH_SMALLEST_PRIME_FRACTION_H

/* GIVEN: 
 *      Sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. 
 *      And an integer k.
 *        
 *      For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
 *        
 * RETURN: 
 *      k-th smallest fraction considered. 
 *      format is an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
 *      
 * EXAMPLE:
 *      Input: arr = [1,2,3,5], k = 3
 *      Output: [2,5]
 *      Explanation: The fractions to be considered in sorted order are: /5, 1/3, 2/5, 1/2, 3/5, and 2/3.
 *      The third fraction is 2/5.
 *      
 *  URL: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
 *  LEETCODE: #786 K-th Smallest Prime Fraction.
*/

#include <vector>

std::vector<int> kthSmallestPrimeFraction(const std::vector<int> &arr, int k);

namespace Test {
void kthSmallestPrimeFraction();
}

#endif // KTH_SMALLEST_PRIME_FRACTION_H
