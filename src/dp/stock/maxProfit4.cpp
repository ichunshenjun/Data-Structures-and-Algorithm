// 123
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(int k, vector<int>& prices);
int main() {
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(k, prices) << endl;
    return 0;
}
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    for (int j = 0; j <= k; j++) dp[0][j][1] = -prices[0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][k][0];
}