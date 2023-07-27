// 494
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> memo;
int findTargetSumWays(vector<int>& nums, int target);
int dp(vector<int>& nums, int i, int target);
int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}
int findTargetSumWays(vector<int>& nums, int target) { return dp(nums, 0, target); }
int dp(vector<int>& nums, int i, int target) {
    if (i == (int)nums.size()) {
        if (target == 0) {
            return 1;
        }
        return 0;
    }
    string key = to_string(i) + "," + to_string(target);
    if (memo.count(key)) {
        return memo[key];
    }
    int result = dp(nums, i + 1, target - nums[i]) + dp(nums, i + 1, target + nums[i]);
    memo[key] = result;
    return result;
}