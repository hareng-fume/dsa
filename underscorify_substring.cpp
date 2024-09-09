#include "underscorify_substring.h"

#include <iostream>
#include <utility>
#include <vector>

namespace Impl {
std::string _underscorifySubstring(const std::string &i_str, const std::string &i_substring)
{
    std::vector<std::pair<int, int>> locations;

    int startIdx = i_str.find(i_substring);
    while (startIdx > -1) {
        locations.push_back({startIdx, startIdx + i_substring.size()});
        startIdx = i_str.find(i_substring, startIdx + 1);
    }

    if (locations.empty())
        return i_str;

    std::vector<std::pair<int, int>> collapsedLocations{locations.front()};
    for (int i = 1; i < locations.size(); ++i) {
        auto &[_, prevEnd] = collapsedLocations.back();
        const auto &[currStart, currEnd] = locations[i];

        if (prevEnd < currStart)
            collapsedLocations.push_back(locations[i]);
        else
            prevEnd = currEnd;
    }

    std::string underscorified;
    int strIdx = 0, locationIdx = 0;
    while (strIdx < i_str.size() && locationIdx < collapsedLocations.size()) {
        while (strIdx < collapsedLocations[locationIdx].first) {
            underscorified.push_back(i_str[strIdx]);
            strIdx += 1;
        }
        underscorified.push_back('_');

        while (strIdx < collapsedLocations[locationIdx].second) {
            underscorified.push_back(i_str[strIdx]);
            strIdx += 1;
        }
        underscorified.push_back('_');
        locationIdx += 1;
    }

    while (strIdx < i_str.size()) {
        underscorified.push_back(i_str[strIdx]);
        strIdx += 1;
    }

    return underscorified;
}
} // namespace Impl

namespace Test {
void underscorifySubstring()
{
    std::string str{"testthis is a testtest to see if testestest it works"};
    std::string substr{"test"};
    const auto underscorified = Impl::_underscorifySubstring(str, substr);
    if (underscorified == "_test_this is a _testtest_ to see if _testestest_ it works")
        std::cout << "OK: \"_test_this is a _testtest_ to see if _testestest_ it works\""
                  << std::endl;
    else
        std::cout << "NOK: expected: \"_test_this is a _testtest_ to see if _testestest_ it "
                     "works\", actual: "
                  << underscorified << std::endl;
}
} // namespace Test
