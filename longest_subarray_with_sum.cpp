#include "longest_subarray_with_sum.h"
#include "utils.h"

#include <functional>
#include <iostream>

namespace Impl {

std::vector<int> _Naive(std::vector<int> array, int targetSum)
{
    std::vector<int> indices;

    for (int startIdx = 0; startIdx < array.size(); ++startIdx) {
        int subarraySum = 0;
        for (int endIdx = startIdx; endIdx < array.size(); ++endIdx) {
            subarraySum += array[endIdx];

            if (subarraySum == targetSum) {
                if (indices.empty() || indices[1] - indices[0] < endIdx - startIdx)
                    indices = {startIdx, endIdx};
            }
        }
    }
    return indices;
}

std::vector<int> _SlidingWindow(std::vector<int> array, int targetSum)
{
    std::vector<int> indices;

    int startIdx = 0, endIdx = 0;
    int slidingSum = 0;

    while (endIdx < array.size()) {
        slidingSum += array[endIdx];

        while (startIdx < endIdx && slidingSum > targetSum) {
            slidingSum -= array[startIdx];
            startIdx += 1;
        }

        if (slidingSum == targetSum) {
            if (indices.empty() || indices[1] - indices[0] < endIdx - startIdx)
                indices = {startIdx, endIdx};
        }

        endIdx += 1;
    }

    return indices;
}

void longestSubarrayWithSum(std::function<std::vector<int>(std::vector<int>, int)> i_func)
{
    std::vector<int> arr{1, 2, 3, 4, 3, 3, 1, 2, 1};
    int targetSum = 10;
    auto longestSequence = i_func(arr, targetSum);

    std::cout << "input: {1,2,3,4,3,3,1,2,1}, target_sum: 10\n";
    if (longestSequence[0] == 4 && longestSequence[1] == 8)
        std::cout << "OK: [4,8]\n";
    else
        std::cout << "NOK: actual: [" << longestSequence[0] << "," << longestSequence[1]
                  << "], expected: [4,8]\n";

    arr = {1, 2, 3, 4, 5};
    targetSum = 0;
    longestSequence = i_func(arr, targetSum);

    std::cout << "input: {1,2,3,4,5}, target_sum: 0\n";
    if (longestSequence.empty())
        std::cout << "OK: {}\n";
    else
        std::cout << "NOK: actual: [" << longestSequence[0] << "," << longestSequence[1]
                  << "], expected: {}\n";
}

} // namespace Impl

namespace Test {

void longestSubarrayWithSum_Naive()
{
    Impl::longestSubarrayWithSum(Impl::_Naive);
}
void longestSubarrayWithSum_SlidingWindow()
{
    Impl::longestSubarrayWithSum(Impl::_SlidingWindow);
}

} // namespace Test
