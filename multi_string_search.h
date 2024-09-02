#ifndef MULTI_STRING_SEARCH_H
#define MULTI_STRING_SEARCH_H

#include <string>
#include <vector>

std::vector<bool> multiStringSearch_naive(const std::string &i_bigString,
                                          std::vector<std::string> &i_smallStrings);

std::vector<bool> multiStringSearch_TrieBigStr(const std::string &i_bigString,
                                               std::vector<std::string> &i_smallStrings);

std::vector<bool> multiStringSearch_TrieSmallStrs(const std::string &i_bigString,
                                                  std::vector<std::string> &i_smallStrings);

#endif // MULTI_STRING_SEARCH_H
