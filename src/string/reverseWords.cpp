#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    if (s.empty()) return "";
    s += " ";
    string temp = "";
    vector<string> res;
    for (auto ch : s) {
        if (ch == ' ') {
            if (!temp.empty()) {
                res.push_back(temp);
                temp.clear();
            }
        } else
            temp += ch;
    }
    s.clear();
    reverse(res.begin(), res.end());
    for (auto str : res) s += str + ' ';
    if (s.size()) s.pop_back();
    return s;
}

int main() {
    string s = " ";
    cout << reverseWords(s) << endl;
    return 0;
}