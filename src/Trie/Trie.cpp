#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Trie {
public:
    char c;
    vector<Trie*> children;
    bool isEnd;
    Trie() {
        isEnd = false;
        c = 0;
        children = vector<Trie*>(26, nullptr);
    }
    Trie(char c) {
        isEnd = false;
        this->c = c;
        children = vector<Trie*>(26, nullptr);
    }
    ~Trie() {
        for (auto child : children) {
            if (child) delete child;
        }
    }
    void insert(string word) {
        auto cur_node = this;
        for (auto c : word) {
            if (cur_node->children[c - 'a'] == nullptr) {
                auto child = new Trie(c);
                cur_node->children[c - 'a'] = child;
            }
            cur_node = cur_node->children[c - 'a'];
        }
        cur_node->isEnd = true;
    }
    bool search(string word) {
        auto cur_node = this;
        for (auto c : word) {
            auto child = cur_node->children[c - 'a'];
            if (child == nullptr) {
                return false;
            }
            cur_node = child;
        }
        if (cur_node->isEnd == true) return true;
        return false;
    }

    bool startsWith(string prefix) {
        auto cur_node = this;
        for (auto c : prefix) {
            auto child = cur_node->children[c - 'a'];
            if (child == nullptr) {
                return false;
            }
            cur_node = child;
        }
        return true;
    }
};
int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;    // 返回 True
    cout << trie->search("app") << endl;      // 返回 False
    cout << trie->startsWith("app") << endl;  // 返回 True
    trie->insert("app");
    cout << trie->search("app") << endl;  // 返回 True
    delete trie;
    return 0;
}