#include "diagonal_traverse.h"
#include "utils.h"

#include <queue>
#include <unordered_map>

std::vector<int> findDiagonalOrder_bfs(std::vector<std::vector<int>> &nums)
{
    std::queue<std::pair<int, int>> diagonalOrder;
    diagonalOrder.push({0, 0});

    std::vector<int> flattenNums;
    while (!diagonalOrder.empty()) {
        const auto [rowIdx, colIdx] = diagonalOrder.front();
        diagonalOrder.pop();

        flattenNums.push_back(nums[rowIdx][colIdx]);

        if (colIdx == 0 && rowIdx + 1 < nums.size())
            diagonalOrder.push({rowIdx + 1, colIdx});
        if (colIdx + 1 < nums[rowIdx].size())
            diagonalOrder.push({rowIdx, colIdx + 1});
    }

    return flattenNums;
}

// hash-map group-by diagonal id approach
std::vector<int> findDiagonalOrder_hashmap(std::vector<std::vector<int>> &nums)
{
    std::unordered_map<int, std::vector<int>> valuesByDiagId;

    int totalElementsNumber = 0;
    for (int rowIdx = nums.size() - 1; rowIdx >= 0; --rowIdx) {
        totalElementsNumber += nums[rowIdx].size();
        for (int colIdx = 0; colIdx < nums[rowIdx].size(); ++colIdx) {
            const int diagId = rowIdx + colIdx;
            valuesByDiagId[diagId].push_back(nums[rowIdx][colIdx]);
        }
    }

    std::vector<int> flattenNums;
    flattenNums.reserve(totalElementsNumber);

    int diagId = 0;
    while (valuesByDiagId.count(diagId) > 0) {
        for (const int val : valuesByDiagId[diagId])
            flattenNums.push_back(val);
        diagId += 1;
    }
    return flattenNums;
}

namespace Test {

void findDiagonalOrder(const Approach i_approach)
{
    std::vector<std::vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    const auto _findDiagonalOrder = i_approach == Approach::BFS ? findDiagonalOrder_bfs
                                                                : findDiagonalOrder_hashmap;

    auto flattenArr = _findDiagonalOrder(arr);
    if (flattenArr == std::vector<int>{1, 4, 2, 7, 5, 3, 8, 6, 9})
        std::cout << "OK: {1,4,2,7,5,3,8,6,9}" << std::endl;
    else {
        std::cout << "NOK: \nexpected {1,4,2,7,5,3,8,6,9}\nactual: ";
        Utils::print(flattenArr);
    }

    arr = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10}, {11}};
    flattenArr = _findDiagonalOrder(arr);
    if (flattenArr == std::vector<int>{1, 6, 2, 8, 7, 3, 9, 4, 11, 10, 5})
        std::cout << "OK: {1,6,2,8,7,3,9,4,11,10,5}" << std::endl;
    else {
        std::cout << "NOK: \nexpected {1,6,2,8,7,3,9,4,11,10,5}\nactual: ";
        Utils::print(flattenArr);
    }

    arr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    flattenArr = _findDiagonalOrder(arr);
    if (flattenArr == std::vector<int>{1, 3, 2, 5, 4, 7, 6, 9, 8, 10})
        std::cout << "OK: {1,3,2,5,4,7,6,9,8,10}" << std::endl;
    else {
        std::cout << "NOK: \nexpected {1,3,2,5,4,7,6,9,8,10}\nactual: ";
        Utils::print(flattenArr);
    }

    arr = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
    flattenArr = _findDiagonalOrder(arr);
    if (flattenArr == std::vector<int>{1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16})
        std::cout << "OK: {1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16}" << std::endl;
    else {
        std::cout << "NOK: \nexpected {1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16}\nactual: ";
        Utils::print(flattenArr);
    }
}
} // namespace Test
