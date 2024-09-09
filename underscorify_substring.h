#ifndef UNDERSCORIFY_SUBSTRING_H
#define UNDERSCORIFY_SUBSTRING_H

/* [AE][H][Underscorify Substring]
 *
 * GIVEN: main string and a potential substring of the main string.
 *
 * RETURN: version of the main string with every instance of the substring in it wrapped between underscores.
 *
 * NOTE: if two or more instances of the substring in the main string overlap each other or
 *       sit side by side, the underscores relevant to these substrings should only appear on the far left of the leftmost
 *       substring and on the far right of the rightmost substring.
 *       if the main string doesn't contain the other string at all, the function should return the main string intact.
 *
 * E.G.:
 *       input:
 *          string: "testthis is a testtest to see if testestest it works"
 *          substring: "test"
 *
 *       output:
 *          "_test_this is a _testtest_ to see if _testestest_ it works"
*/

#include <string>

std::string underscorifySubstring(const std::string &i_str, const std::string &i_substring);

namespace Test {
void underscorifySubstring();
}

#endif // UNDERSCORIFY_SUBSTRING_H
