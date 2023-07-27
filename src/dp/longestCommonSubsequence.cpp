// 1143
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
int longestCommonSubsequence(string text1, string text2);
int dp(string& text1, int i, string& text2, int j);  // 这里得传引用否则超时
int main() {
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    memo = vector<vector<int>>(m, vector<int>(n, -1));
    return dp(text1, m - 1, text2, n - 1);
}
int dp(string& text1, int i, string& text2, int j) {
    if (i == -1) {
        return 0;
    }
    if (j == -1) {
        return 0;
    }
    if (memo[i][j] != -1) return memo[i][j];
    if (text1[i] == text2[j]) {
        memo[i][j] = dp(text1, i - 1, text2, j - 1) + 1;
        return memo[i][j];
    }
    memo[i][j] = max(dp(text1, i - 1, text2, j), dp(text1, i, text2, j - 1));
    return memo[i][j];
}