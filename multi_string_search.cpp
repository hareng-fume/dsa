#include "multi_string_search.h"

#include <memory>
#include <optional>
#include <unordered_map>
#include <unordered_set>

namespace {

//-----------------------------------------------------------------------------
bool _isInBigStringHelper(const std::string &i_bigString,
                          int i_startIdx,
                          const std::string &i_string)
{
    int leftBigIdx = i_startIdx, rightBigIdx = i_startIdx + i_string.size() - 1;
    int leftSmallIdx = 0, rightSmallIdx = i_string.size() - 1;

    while (leftBigIdx <= rightBigIdx) {
        if (i_bigString[leftBigIdx] != i_string[leftSmallIdx] // small optimization
            || i_bigString[rightBigIdx] != i_string[rightSmallIdx])
            return false;
        leftBigIdx += 1;
        rightBigIdx -= 1;
        leftSmallIdx += 1;
        rightBigIdx -= 1;
    }
    return true;
}

bool _isInBigString(const std::string &i_string, const std::string &i_bigString)
{
    for (int i = 0; i < i_bigString.size(); ++i) {
        if (i + i_string.size() > i_bigString.size()) // small optimization
            break;
        if (_isInBigStringHelper(i_bigString, i, i_string))
            return true;
    }
    return false;
}

//-----------------------------------------------------------------------------
// used in the big string case
//-----------------------------------------------------------------------------
class SuffixTrie final
{
public:
    struct Node
    {
        std::unordered_map<char, std::unique_ptr<Node>> children;
    };

    explicit SuffixTrie(const std::string &i_string)
        : mp_root(std::make_unique<Node>())
    {
        _populateFrom(i_string);
    }

    SuffixTrie(SuffixTrie &&) = default;
    SuffixTrie &operator=(SuffixTrie &&) = default;
    ~SuffixTrie() = default;

    SuffixTrie(const SuffixTrie &) = delete;
    SuffixTrie &operator=(const SuffixTrie &) = delete;

    bool contains(const std::string &i_string) const
    {
        auto *p_node = mp_root.get();
        for (int i = 0; i < i_string.size(); ++i) {
            const auto letter = i_string[i];
            if (p_node->children.count(letter) < 1)
                return false;
            p_node = p_node->children[letter].get();
        }
        return true;
    }

private:
    void _populateFrom(const std::string &i_string)
    {
        for (int i = 0; i < i_string.size(); ++i) {
            auto *p_node = mp_root.get();
            for (int j = i; j < i_string.size(); ++j) {
                const auto letter = i_string[j];
                if (p_node->children.count(letter) < 1)
                    p_node->children[letter] = std::make_unique<Node>();
                p_node = p_node->children[letter].get();
            }
        }
    }

private:
    std::unique_ptr<Node> mp_root;
};

//-----------------------------------------------------------------------------
// used in the small strings case
//-----------------------------------------------------------------------------
class Trie final
{
public:
    struct Node
    {
        std::unordered_map<char, std::unique_ptr<Node>> children;
        std::optional<std::string> data;
    };

public:
    Trie()
        : m_endSymbol('*')
        , mp_root(std::make_unique<Node>())
    {}

    void insert(const std::string &i_string)
    {
        auto *p_node = mp_root.get();
        for (const auto letter : i_string) {
            if (p_node->children.count(letter) < 1) {
                p_node->children[letter] = std::make_unique<Node>();
            }
            p_node = p_node->children[letter].get();
        }
        p_node->children[m_endSymbol] = nullptr;
        p_node->data = i_string;
    }

    Node *get() const { return mp_root.get(); }
    const char getEndSymbol() const { return m_endSymbol; }

private:
    const char m_endSymbol;
    std::unique_ptr<Node> mp_root;
};

void _findSmallStringsIn(const std::string &i_string,
                         int i_startIdx,
                         const Trie &i_trie,
                         std::unordered_set<std::string> &o_contained_strings)
{
    auto *p_node = i_trie.get();
    for (int i = i_startIdx; i < i_string.size(); ++i) {
        if (p_node->children.count(i_string[i]) < 1)
            break;
        p_node = p_node->children[i_string[i]].get();
        if (p_node->children.count(i_trie.getEndSymbol()) > 0)
            o_contained_strings.insert(*p_node->data);
    }
}

} // namespace

//-----------------------------------------------------------------------------
// naive solution with some practical optimizations
// time: O(B*N*S); space: O(N)
// where:
//       B is the length of i_bigString,
//       N is the length of i_smallStrings,
//       S is the length of the largest string in i_smallStrings.
//-----------------------------------------------------------------------------
std::vector<bool> multiStringSearch_naive(const std::string &i_bigString,
                                          std::vector<std::string> &i_smallStrings)
{
    std::vector<bool> result(i_smallStrings.size(), false);
    for (int i = 0; i < i_smallStrings.size(); ++i) {
        if (_isInBigString(i_smallStrings[i], i_bigString))
            result[i] = true;
    }
    return result;
}

//-----------------------------------------------------------------------------
// time: O(B^2+N*S); space: O(B^2+N)
//-----------------------------------------------------------------------------
std::vector<bool> multiStringSearch_TrieBigStr(const std::string &i_bigString,
                                               std::vector<std::string> &i_smallStrings)
{
    // time: O(B^2), where B is the length of i_bigString
    // space: O(B^2), if the input i_bigString contains small number of repetitive symbols
    SuffixTrie suffixTrie(i_bigString);

    // space: O(N), where M is the length of the input array of small strings.
    std::vector<bool> result(i_smallStrings.size(), false);

    // time: O(N*S), where N is the length of i_smallStrings, S is the length of the longest small string
    for (int i = 0; i < i_smallStrings.size(); ++i) {
        if (suffixTrie.contains(i_smallStrings[i]))
            result[i] = true;
    }

    return result;
}

//-----------------------------------------------------------------------------
// time: O(N*S + B*S); space: O(N*S)
//-----------------------------------------------------------------------------
std::vector<bool> multiStringSearch_TrieSmallStrs(const std::string &i_bigString,
                                                  std::vector<std::string> &i_smallStrings)
{
    // time: O(N*S), where N is the length of i_smallStrings, S is the length of the longest small string
    // space: O(N*S)
    Trie trie;
    for (const auto &str : i_smallStrings)
        trie.insert(str);

    // time: O(B*S), where B is the length of i_bigString, S is the length of the longest small string
    std::unordered_set<std::string> containedStrings;
    for (int i = 0; i < i_bigString.size(); ++i)
        _findSmallStringsIn(i_bigString, i, trie, containedStrings);

    std::vector<bool> result(i_smallStrings.size(), false);
    for (int i = 0; i < i_smallStrings.size(); ++i) {
        if (containedStrings.count(i_smallStrings[i]) > 0)
            result[i] = true;
    }
    return result;
}
