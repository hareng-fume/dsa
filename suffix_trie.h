#ifndef SUFFIX_TRIE_H
#define SUFFIX_TRIE_H

#include <memory>
#include <string>
#include <unordered_map>

/* time and space complexity:
 * [Creation]: time => O(N^2), where N is the length of the input string;
 *                             we add N symbol suffix, then N-1 symbol suffix, ... , 1 symbol suffix;
 *                             we iterate over all of the suffixes of the input string, adding them one-by-one to the tree
 *                             (two nested for-loops);
 *             space => O(N^2), in the case when there is no repeating symbols in the input string,
 *                              or too few reapeating symbols.
 *                   => O(N), in the case when the input string contains the same symbol repeating over and over again
 *                            e.g. "aaaaaaaaa";
 *
 * [Search]: time => O(M), where M is the length of the string (suffix) to find (the string we are looking for)
 *           space => O(1), no extra space is needed.
 */
class SuffixTrie final
{
public:
    struct Node
    {
        std::unordered_map<char, std::unique_ptr<Node>> children;
    };

    explicit SuffixTrie(const std::string &i_string);
    ~SuffixTrie() = default;

    SuffixTrie(const SuffixTrie &) = delete;
    SuffixTrie &operator=(const SuffixTrie &) = delete;
    SuffixTrie(SuffixTrie &&) = default;
    SuffixTrie &operator=(SuffixTrie &&) = default;

    // API
    bool Contains(const std::string &i_string) const;

private:
    void _PopulateFrom(const std::string &i_string);

private:
    char m_endSymbol;
    std::unique_ptr<Node> m_root;
};

#endif // SUFFIX_TRIE_H
