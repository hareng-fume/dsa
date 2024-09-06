#include "utils.h"

#include <iostream>

namespace Utils {

//-----------------------------------------------------------------------------
void printVectorInt2D(const std::vector<std::vector<int>> &i_vector2D)
{
    for (int i = 0; i < i_vector2D.size(); ++i)
        printVector(i_vector2D[i]);
    std::cout << "\n";
}

}; // namespace Utils
