#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

namespace Utils {

template<typename T1, template<typename T2, class Allocator = std::allocator<T2>> class Container>
inline void print(const Container<T1> &i_container)
{
    std::cout << "{";
    auto it = i_container.begin();
    if (it != i_container.end()) {
        std::cout << *it;
        ++it;

        while (it != i_container.end()) {
            std::cout << "," << *it;
            ++it;
        }
    }

    std::cout << "}\n";
}

void printVectorInt2D(const std::vector<std::vector<int>> &i_vector2D);

}; // namespace Utils

#endif // UTILS_H
