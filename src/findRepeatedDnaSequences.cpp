#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<string> findRepeatedDnaSequences(string s);
int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto res = findRepeatedDnaSequences(s);
    for (auto str : res) {
        cout << str << endl;
    }
    return 0;
}
vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen;
    unordered_set<string> res;
    for (int i = 0; i + 10 <= static_cast<int>(s.size()); i++) {
        string str = s.substr(i, 10);
        if (seen.find(str) != seen.end()) {
            res.insert(str);
        } else {
            seen.insert(str);
        }
    }
    return vector<string>(res.begin(), res.end());
}