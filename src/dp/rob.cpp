#include <iostream>
#include <vector>
using namespace std;
vector<int> memo;
int rob(vector<int>& nums);
int dp(vector<int>& nums, int i);
int main() {
    vector<int> nums = {200, 3, 140, 20, 10};
    cout << rob(nums) << endl;
    return 0;
}
int rob(vector<int>& nums) {
    memo = vector<int>(nums.size(), -1);
    return dp(nums, nums.size() - 1);
}
int dp(vector<int>& nums, int i) {
    if (i < 0) {
        return 0;
    }
    if (i == 0) {
        return nums[0];
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    auto res = max(dp(nums, i - 2) + nums[i], dp(nums, i - 1));
    memo[i] = res;
    return res;
}
// int flag = 0;
// int rob(vector<int>& nums) {
//     memo = vector<int>(nums.size(), -1);
//     flag = 1;
//     int a = dp(nums, nums.size() - 2);
//     memo = vector<int>(nums.size(), -1);
//     flag = 0;
//     int b = dp(nums, nums.size() - 1);
//     if (nums.size() == 1) return nums[0];
//     return max(a, b);
// }
// int dp(vector<int>& nums, int i) {
//     if (i < 0) {
//         return 0;
//     }
//     if (i == 0) {
//         if (flag == 1) return nums[0];
//         return 0;
//     }
//     if (memo[i] != -1) {
//         return memo[i];
//     }
//     auto res = max(dp(nums, i - 2) + nums[i], dp(nums, i - 1));
//     memo[i] = res;
//     return res;
// }