#include "suffix_trie.h"

namespace {
void _Insert(const std::string &i_string,
             int i_startIdx,
             SuffixTrie::Node &o_node,
             const char i_endSymbol)
{
    auto *p_node = &o_node;
    for (int i = i_startIdx; i < i_string.size(); ++i) {
        const auto letter = i_string[i];
        if (p_node->children.count(letter) < 1)
            p_node->children[letter] = std::make_unique<SuffixTrie::Node>();
        p_node = p_node->children[letter].get();
    }
    p_node->children[i_endSymbol] = nullptr;
}
} // namespace

//-----------------------------------------------------------------------------
SuffixTrie::SuffixTrie(const std::string &i_string)
    : m_endSymbol('*')
    , m_root(std::make_unique<Node>())
{
    _PopulateFrom(i_string);
}

//-----------------------------------------------------------------------------
void SuffixTrie::_PopulateFrom(const std::string &i_string)
{
    for (int i = 0; i < i_string.size(); ++i)
        _Insert(i_string, i, *m_root, m_endSymbol);
}

//-----------------------------------------------------------------------------
bool SuffixTrie::Contains(const std::string &i_string) const
{
    auto *p_node = m_root.get();
    for (const char letter : i_string) {
        if (p_node->children.count(letter) < 1)
            return false;
        p_node = p_node->children[letter].get();
    }

    if (p_node->children.count(m_endSymbol) < 1)
        return false;

    return true;
}
