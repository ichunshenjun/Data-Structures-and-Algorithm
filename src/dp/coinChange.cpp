#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    sort(coins.begin(), coins.end(), greater<int>());
    vector<long> dp(amount + 1, INT64_MAX - 1);
    for (int i = coins.size() - 1; i >= 0 && coins[i] <= amount; i--) {
        dp[coins[i]] = 1;
    }
    for (int i = coins[coins.size() - 1]; i <= amount; i++) {
        for (int j = coins.size() - 1; j >= 0 && coins[j] <= i; j--) {
            dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        }
    }
    if (dp[amount] == INT64_MAX - 1) return -1;
    return dp[amount];
}
int main() {
    vector<int> coins = {1, 2147483647};
    int amount = 2;
    auto res = coinChange(coins, amount);
    cout << res << endl;
    return 0;
}