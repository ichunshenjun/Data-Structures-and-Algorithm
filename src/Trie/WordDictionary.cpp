#include <iostream>
#include <string>
#include <vector>
using namespace std;
class WordDictionary {
public:
    char c;
    vector<WordDictionary*> children;
    bool isEnd;
    WordDictionary() {
        isEnd = false;
        c = 0;
        children = vector<WordDictionary*>(26, nullptr);
    }
    WordDictionary(char c) {
        isEnd = false;
        this->c = c;
        children = vector<WordDictionary*>(26, nullptr);
    }
    ~WordDictionary() {
        for (auto child : children) {
            if (child) delete child;
        }
    }
    void addWord(string word) {
        auto cur_node = this;
        for (auto c : word) {
            if (cur_node->children[c - 'a'] == nullptr) {
                auto child = new WordDictionary(c);
                cur_node->children[c - 'a'] = child;
            }
            cur_node = cur_node->children[c - 'a'];
        }
        cur_node->isEnd = true;
    }

    bool search(string word) {
        auto cur_node = this;
        int index = 0;
        if (word.size() == 0 && isEnd == true) {
            return true;
        }
        for (auto c : word) {
            index++;
            if (c == '.') {
                for (auto child : cur_node->children) {
                    if (child != nullptr && child->search(word.substr(index))) {
                        return true;
                    }
                }
                return false;
            } else {
                auto child = cur_node->children[c - 'a'];
                if (child == nullptr) {
                    return false;
                }
                cur_node = child;
            }
        }
        if (cur_node->isEnd == true) return true;
        return false;
    }
};
int main() {
    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("at");
    wordDictionary->addWord("ab");
    cout << wordDictionary->search(".a") << endl;
    cout << wordDictionary->search(".") << endl;
    delete wordDictionary;
    return 0;
}