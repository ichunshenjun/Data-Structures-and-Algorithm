// 1312
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
int minInsertions(string s);
int dp(string& s, int i, int j);
int main() {
    string s = "leetcode";
    cout << minInsertions(s) << endl;
    return 0;
}
int minInsertions(string s) {
    int m = s.size();
    memo = vector<vector<int>>(m, vector<int>(m, -1));
    return dp(s, 0, s.size() - 1);
}
int dp(string& s, int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (memo[i][j] != -1) return memo[i][j];
    if (s[i] == s[j])
        memo[i][j] = dp(s, i + 1, j - 1);
    else {
        memo[i][j] = min(dp(s, i + 1, j) + 1, dp(s, i, j - 1) + 1);
    }
    return memo[i][j];
}