#include <iostream>

#include "diagonal_traverse.h"
#include "kth_smallest_prime_fraction.h"
#include "longest_subarray_with_sum.h"
#include "safest_path_in_grid.h"

int main()
{
    Test::longestSubarrayWithSum_Naive();
    Test::longestSubarrayWithSum_SlidingWindow();

    return 0;
}
