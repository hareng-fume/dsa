#include "utils.h"

#include <iostream>

namespace Utils {

//-----------------------------------------------------------------------------
void printVectorInt(const std::vector<int> &i_vector)
{
    std::cout << "{";
    if (i_vector.size() > 0)
        std::cout << i_vector[0];
    for (int i = 1; i < i_vector.size(); ++i)
        std::cout << ", " << i_vector[i];
    std::cout << "}\n";
}

//-----------------------------------------------------------------------------
void printVectorInt2D(const std::vector<std::vector<int>> &i_vector2D)
{
    for (int i = 0; i < i_vector2D.size(); ++i)
        printVectorInt(i_vector2D[i]);
    std::cout << "\n";
}

}; // namespace Utils
