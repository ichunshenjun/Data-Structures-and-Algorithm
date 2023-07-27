// 139、140
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<string> memo[1001];
unordered_set<string> wordSet;
vector<string> dp(string s, int i);
vector<string> wordBreak(string s, vector<string>& wordDict);
int main() {
    string s = "cars";
    vector<string> wordDict = {"car", "ca", "rs"};
    auto res = wordBreak(s, wordDict);
    for (auto str : res) cout << str;
    cout << endl;
    return 0;
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    for (auto word : wordDict) wordSet.insert(word);
    return dp(s, 0);
}
vector<string> dp(string s, int i) {
    vector<string> res;
    if (i == (int)s.size()) {
        res.push_back("");
        return res;
    }
    if (!(memo[i].empty())) {
        return memo[i];
    }
    for (int len = 1; i + len <= (int)s.size(); len++) {
        string prefix = s.substr(i, len);
        if (wordSet.count(prefix)) {
            auto subProblem = dp(s, i + len);
            for (string sub : subProblem) {
                if (sub.empty()) {
                    res.push_back(prefix);
                } else {
                    res.push_back(prefix + " " + sub);
                }
            }
        }
    }
    memo[i] = res;
    return res;
}