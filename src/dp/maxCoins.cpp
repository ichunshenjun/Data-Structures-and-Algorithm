// 312
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
int maxCoins(vector<int>& nums);
int dp(vector<int>& nums, int i, int j);
int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
    return 0;
}
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> points(n + 2, 1);
    for (int i = 1; i <= n; i++) points[i] = nums[i - 1];
    memo = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));
    return dp(points, 0, n + 1);
}
int dp(vector<int>& nums, int i, int j) {
    int res = 0;
    if (memo[i][j] != -1) return memo[i][j];
    for (int k = i + 1; k <= j - 1; k++) {
        res = max(res, dp(nums, i, k) + dp(nums, k, j) + nums[i] * nums[k] * nums[j]);
    }
    memo[i][j] = res;
    return res;
}