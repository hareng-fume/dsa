// Type your code here, or load an example.

#include <queue>
#include <vector>
#include <iostream>

// given an array of n elements, where each element is at most k positions away from its target position.
// sort this array in O(n*log(k))

void sort(std::vector<int>& array, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(array.begin(), array.begin() + k + 1);

    int i = 0, j = k;
    while (j < array.size()) {
        array[i] = min_heap.top();
        min_heap.pop();

        ++j; ++i;
        if (j < array.size())
            min_heap.push(array[j]);
    }

    while (!min_heap.empty()) {
        array[i] = min_heap.top();
        min_heap.pop();
        ++i;
    }
}

void print(const std::vector<int>& v) {
    std::cout << "{";
    if(!v.empty()) {
        std::cout << v.front();
        for(int i = 1; i < v.size(); ++i)
            std::cout << ", " << v[i];
    }

    std::cout << "}\n";
}

int main() {
    
    std::vector<int> v {6,5,3,2,8,10,9}; int k = 3;
    print(v);
    sort(v, k);
    print(v);
    std::cout << "\n\n";

    v = {10,9,8,7,4,70,60,50}; k = 4;
    print(v);
    sort(v, k);
    print(v);

    return 0;
}