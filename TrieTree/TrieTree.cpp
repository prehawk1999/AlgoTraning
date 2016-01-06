/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

搜索字典项目的方法为：
(1) 从根结点开始一次搜索；
(2) 取得要查找关键词的第一个字母，并根据该字母选择对应的子树并转到该子树继续进行检索；
(3) 在相应的子树上，取得要查找关键词的第二个字母,并进一步选择对应的子树进行检索。
(4) 迭代过程……
(5) 在某个结点处，关键词的所有字母已被取出，则读取附在该结点上的信息，即完成查找。
其他操作类似处理
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <assert.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;



namespace {

static const int offset   = 97;
static const int capacity = 26;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c = 0) {
        _child_nodes.resize(capacity, NULL);
        _character  = c;
        _freq       = 0;
    }

    void insert(TrieNode *nod) {
        char c = nod->character();
        assert(c != 0);
        assert(node(c) == NULL);
        _child_nodes[index(c)] = nod;
    }

    TrieNode* node(char c) const {return _child_nodes[index(c)];}
    void add(int add) {_freq += add;}
    int  index(char c) const {return (int)c - offset;}
    bool root() const {return _character == 0;}
    char character() const {return _character;}
    int  frequency() const {return _freq;}

private:
    vector<TrieNode*> _child_nodes;
    char              _character;
    int               _freq;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {

        TrieNode *current = root;
        for(auto it = word.begin(); it != word.end(); ++it)
        {
            char c = *it;
            if(current->node(c) == NULL) {
                current->insert(new TrieNode(c));
            }
            current = current->node(c);
        }
        assert(current);
        current->add(1);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return _search(word, false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return _search(prefix, true);
    }

    bool _search(string word, bool ignoreLast) {
        TrieNode *current = root;
        for(auto it = word.begin(); it != word.end(); ++it) {
            char c = *it;
            if(current->node(c) == NULL) return false;
            current = current->node(c);
        }
        return (ignoreLast || (current->frequency() <= 0))?true:false;
    }

private:
    TrieNode* root;
};


} // namespace

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main(int argc, char const *argv[])
{
    ifstream ifs;
    ifs.open("word.txt", std::ifstream::in);
    auto tree = new Trie();
    tree->insert("ab");
    tree->insert("hell");
    tree->insert("worldhello");
    cout << "is the tree has word <helloworld>?: " << tree->search("a") << endl;
    cout << "is the tree contain <hello>? " << tree->startsWith("a") << endl;
    return 0;
}