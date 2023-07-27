// 72
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
int minDistance(string word1, string word2);
int dp(string word1, int i, string word2, int j);
int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2) << endl;
    return 0;
}
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    memo = vector<vector<int>>(m, vector<int>(n, -1));
    return dp(word1, m - 1, word2, n - 1);
}
int dp(string word1, int i, string word2, int j) {
    if (i == -1) return j + 1;
    if (j == -1) return i + 1;
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (word1[i] == word2[j]) {
        memo[i][j] = dp(word1, i - 1, word2, j - 1);
        return memo[i][j];
    }
    memo[i][j] =
        min(min(dp(word1, i, word2, j - 1) + 1, dp(word1, i - 1, word2, j) + 1), dp(word1, i - 1, word2, j - 1) + 1);
    return memo[i][j];
}