#include "kth_smallest_prime_fraction.h"

#include <iostream>
#include <queue>

std::vector<int> kthSmallestPrimeFraction(const std::vector<int> &arr, int k)
{
    struct Fraction final
    {
        Fraction(const double &i_value, const int i_numeratorIdx, const int i_denominatorIdx)
            : value(i_value)
            , numeratorIdx(i_numeratorIdx)
            , denominatorIdx(i_denominatorIdx)
        {}

        double value;
        int numeratorIdx, denominatorIdx;
    };
    auto cmp = [](const Fraction &fr1, const Fraction &fr2) { return fr1.value > fr2.value; };

    // Try using min-heap of size k.
    // In c++ it is std::priority_queue with std::greater<T>, where T is double in this case.

    std::priority_queue<Fraction, std::vector<Fraction>, decltype(cmp)> fractionMinHeap(cmp);
    for (int i = 0; i < arr.size() - 1; ++i)
        fractionMinHeap.emplace(1. * arr[i] / arr.back(), i, arr.size() - 1);

    for (int i = 0; i < k - 1; ++i) {
        auto currFraction = fractionMinHeap.top();
        fractionMinHeap.pop();

        currFraction.denominatorIdx -= 1;
        currFraction.value = 1. * arr[currFraction.numeratorIdx] / arr[currFraction.denominatorIdx];

        fractionMinHeap.push(currFraction);
    }

    const auto &smallestFraction = fractionMinHeap.top();
    return {arr[smallestFraction.numeratorIdx], arr[smallestFraction.denominatorIdx]};
}

void test_kthSmallestPrimeFraction()
{
    std::vector<int> arr{1, 2, 3, 5};
    const auto smallestFraction = kthSmallestPrimeFraction(arr, 3);
    std::cout << "result is: [" << smallestFraction[0] << ", " << smallestFraction[1]
              << "], should be: [" << 2 << ", " << 5 << "]" << std::endl;
}
