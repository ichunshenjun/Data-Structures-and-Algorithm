// 10
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, bool> memo;
bool isMatch(string s, string p);
bool dp(string s, int i, string p, int j);
int main() {
    string s = "ab", p = ".*c";
    cout << isMatch(s, p);
    return 0;
}
bool isMatch(string s, string p) { return dp(s, 0, p, 0); }
bool dp(string s, int i, string p, int j) {
    int m = s.size();
    int n = p.size();
    if (i == m) {
        if ((n - j) % 2 == 1) {
            return false;
        }
        for (; j + 1 < n; j += 2) {
            if (p[j + 1] != '*') {
                return false;
            }
        }
        return true;
    }
    if (j == n) {
        return false;
    }
    string key = to_string(i) + "," + to_string(j);
    if (memo.count(key)) {
        return memo[key];
    }
    bool res = false;
    if (s[i] == p[j] || p[j] == '.') {
        if (j + 1 < n && p[j + 1] == '*') {
            res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
        } else {
            res = dp(s, i + 1, p, j + 1);
        }
    } else {
        if (j + 1 < n && p[j + 1] == '*') {
            res = dp(s, i, p, j + 2);
        } else {
            res = false;
        }
    }
    memo[key] = res;
    return res;
}