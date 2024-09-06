#include <iostream>

#include "diagonal_traverse.h"
#include "kth_smallest_prime_fraction.h"
#include "safest_path_in_grid.h"

int main()
{
    Test::findDiagonalOrder(Test::Approach::BFS);
    Test::findDiagonalOrder(Test::Approach::HashMap);

    return 0;
}
