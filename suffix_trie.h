#ifndef SUFFIX_TRIE_H
#define SUFFIX_TRIE_H

#include <memory>
#include <string>
#include <unordered_map>

class SuffixTrie
{
public:
    struct Node
    {
        std::unordered_map<char, std::unique_ptr<Node>> children;
    };

    explicit SuffixTrie(const std::string &i_string);

    // API
    bool Contains(const std::string &i_string) const;

private:
    void _PopulateFrom(const std::string &i_string);

private:
    const char m_endSymbol;
    std::unique_ptr<Node> m_root;
};

#endif // SUFFIX_TRIE_H
