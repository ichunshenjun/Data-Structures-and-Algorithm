// 518
#include <iostream>
#include <vector>
using namespace std;
int change(int amount, vector<int>& coins);
int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(amount, coins) << endl;
    return 0;
}
int change(int amount, vector<int>& coins) {
    int N = coins.size();
    vector<vector<int>> dp(N + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= N; i++) dp[i][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= amount; w++) {
            if (w - coins[i - 1] < 0) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = dp[i][w - coins[i - 1]] + dp[i - 1][w];
            }
        }
    }
    return dp[N][amount];
}