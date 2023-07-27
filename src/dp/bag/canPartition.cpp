// 416
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
bool canPartition(vector<int>& nums);
int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums) << endl;
    return 0;
}
bool canPartition(vector<int>& nums) {
    int N = nums.size();
    int sum = 0;
    for (auto num : nums) {
        sum += num;
    }
    int W = sum / 2;
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - nums[i - 1] < 0) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w - nums[i - 1]] + nums[i - 1], dp[i - 1][w]);
            }
        }
    }
    return dp[N][W] == (double)sum / 2;
}