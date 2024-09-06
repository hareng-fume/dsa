#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

namespace Utils {

template<typename T>
inline void printVector(const std::vector<T> &i_vector)
{
    std::cout << "{";
    if (i_vector.size() > 0)
        std::cout << i_vector[0];
    for (int i = 1; i < i_vector.size(); ++i)
        std::cout << "," << i_vector[i];
    std::cout << "}\n";
}

void printVectorInt2D(const std::vector<std::vector<int>> &i_vector2D);

}; // namespace Utils

#endif // UTILS_H
