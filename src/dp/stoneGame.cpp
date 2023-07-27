// 877
#include <iostream>
#include <vector>
using namespace std;
bool stoneGame(vector<int>& piles);
int main() {
    vector<int> piles = {5, 3, 4, 5};
    cout << stoneGame(piles) << endl;
    return 0;
}
bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = piles[i];
        dp[i][i][1] = 0;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            int left = piles[i] + dp[i + 1][j][1];
            int right = piles[j] + dp[i][j - 1][1];
            if (left > right) {
                dp[i][j][0] = left;
                dp[i][j][1] = dp[i + 1][j][0];
            } else {
                dp[i][j][0] = right;
                dp[i][j][1] = dp[i][j - 1][0];
            }
        }
    }

    return dp[0][n - 1][0] > dp[0][n - 1][1] ? true : false;
}