// 45
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
vector<int> memo;
int jump(vector<int>& nums);
int dp(vector<int>& nums, int i);
int main() {
    vector<int> nums = {2, 1};
    cout << jump(nums) << endl;
    return 0;
}
int jump(vector<int>& nums) {
    memo = vector<int>(nums.size(), -1);
    return dp(nums, 0);
}
int dp(vector<int>& nums, int i) {
    int n = nums.size();
    if (i > n - 1) return INT32_MAX - 1;
    if (i == n - 1) return 0;
    if (memo[i] != -1) return memo[i];
    int res = INT32_MAX - 1;
    for (int j = 1; j <= nums[i]; j++) res = min(res, dp(nums, i + j) + 1);
    memo[i] = res;
    return res;
}