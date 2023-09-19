#include <iostream>
#include <vector>
using namespace std;
vector<int> memo;
int rob(vector<int>& nums);
int dp(vector<int>& nums, int i);
int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 2};
    cout << rob(nums) << endl;
    return 0;
}
// int rob(vector<int>& nums) {
//     memo = vector<int>(nums.size(), -1);
//     return dp(nums, nums.size() - 1);
// }
// int dp(vector<int>& nums, int i) {
//     if (i < 0) {
//         return 0;
//     }
//     if (i == 0) {
//         return nums[0];
//     }
//     if (memo[i] != -1) {
//         return memo[i];
//     }
//     auto res = max(dp(nums, i - 2) + nums[i], dp(nums, i - 1));
//     memo[i] = res;
//     return res;
// }
// 保存打劫的路径
int rob(vector<int>& nums) {
    vector<int> dp(nums.size());
    vector<int> path(nums.size(), -1);
    if (nums.size() == 1) {
        return nums[0];
    }
    dp[0] = nums[0];
    path[0] = 0;
    dp[1] = max(nums[0], nums[1]);
    if (nums[1] > nums[0]) {
        path[1] = 1;
    } else {
        path[1] = 0;
    }
    for (int i = 2; i < (int)nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        if (dp[i] > dp[i - 2] + nums[i]) {
            path[i] = path[i - 1];
        } else {
            path[i] = i;
        }
    }
    vector<int> res;
    int i = nums.size() - 1;
    while (i >= 0) {
        if (path[i] != i) {
            res.push_back(path[i]);
            i = path[i] - 2;
        } else {
            res.push_back(i);
            i = i - 2;
        }
    }
    for (int j = res.size() - 1; j >= 0; j--) {
        cout << res[j] << " ";
    }
    cout << endl;
    return dp[nums.size() - 1];
}