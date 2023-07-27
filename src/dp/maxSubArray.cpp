// 53
#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums);
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    for (int i = 0; i < (int)nums.size(); i++) {
        dp[i] = nums[i];
    }
    int maxSum = dp[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], dp[i]);
        maxSum = dp[i] > maxSum ? dp[i] : maxSum;
    }
    return maxSum;
}
