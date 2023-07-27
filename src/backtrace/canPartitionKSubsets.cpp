// 698
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, bool> memo;
bool canPartitionKSubsets(vector<int>& nums, int k);
bool backtrace(vector<int>& nums, int target, int sum, int start, int k, int visited);
int main() {
    vector<int> nums = {2, 2, 2, 2, 3, 4, 5};
    int k = 4;
    cout << canPartitionKSubsets(nums, k) << endl;
    return 0;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (auto num : nums) sum += num;
    int target = sum / k;
    if (sum % k != 0) return false;
    return backtrace(nums, target, 0, 0, k, 0);
}
bool backtrace(vector<int>& nums, int target, int sum, int start, int k, int visited) {
    if (k == 0) {
        return true;
    }
    if (sum == target) {
        bool res = backtrace(nums, target, 0, 0, k - 1, visited);
        memo[visited] = res;
        return res;
    }
    if (memo.count(visited)) {
        return memo[visited];
    }
    for (int i = start; i < (int)nums.size(); i++) {
        if (((visited >> i) & 1) == 1) {
            continue;
        }
        if (sum + nums[i] > target) {
            continue;
        }
        visited |= 1 << i;
        sum = sum + nums[i];
        if (backtrace(nums, target, sum, i + 1, k, visited)) {
            return true;
        }
        sum = sum - nums[i];
        visited ^= 1 << i;
    }
    return false;
}