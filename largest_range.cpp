#include "largest_range.h"
#include "utils.h"

#include <iostream>
#include <unordered_map>

namespace Impl {

// time: O(N)
// space: O(N)
std::vector<int> _largestRange(const std::vector<int> &array)
{
    std::unordered_map<int, bool> visited;
    for (const auto &element : array)
        visited[element] = false;

    std::vector<int> range;
    for (const auto &element : array) {
        if (visited[element])
            continue;

        visited[element] = true;

        int smaller = element;
        while (visited.count(smaller - 1) > 0) {
            visited[smaller - 1] = true;
            smaller -= 1;
        }

        int larger = element;
        while (visited.count(larger + 1) > 0) {
            visited[larger + 1] = true;
            larger += 1;
        }

        if (range.empty() || range[1] - range[0] < larger - smaller)
            range = {smaller, larger};
    }

    return range;
}
} // namespace Impl

std::vector<int> largestRange(const std::vector<int> &array)
{
    return Impl::_largestRange(array);
}

namespace Test {
void largestRange()
{
    std::vector<int> v{1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
    const auto range = Impl::_largestRange(v);
    if (range == std::vector<int>{0, 7})
        std::cout << "OK, {0,7}" << std::endl;
    else {
        std::cout << "NOK, expected: {0,7}, actual: ";
        Utils::print(range);
    }
}
} // namespace Test
