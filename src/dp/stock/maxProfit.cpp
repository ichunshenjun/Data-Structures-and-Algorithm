// 121
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices);
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, 0)));
    dp[0][1][1] = -prices[0];
    for (int i = 1; i < n; i++) {
        for (int k = 1; k <= 1; k++) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][1][0];
}