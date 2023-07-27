// 918
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int maxSubarraySumCircular(vector<int>& nums);
int dp(vector<int>& nums, int j, int sz);
int main() {
    vector<int> nums = {2, -2, 2, 7, 8, 0};
    cout << maxSubarraySumCircular(nums) << endl;
    return 0;
}
int maxSubarraySumCircular(vector<int>& nums) {
    int sz = nums.size();
    vector<int> leftMax(sz, 0);
    int res = nums[0];
    int leftSum = nums[0];
    leftMax[0] = nums[0];
    int simple = nums[0];
    for (int i = 1; i < sz; i++) {
        simple = max(simple + nums[i], nums[i]);
        leftSum += nums[i];
        leftMax[i] = max(leftMax[i - 1], leftSum);
        res = max(res, simple);
    }
    int rightSum = 0;
    for (int j = sz - 1; j >= 1; j--) {
        rightSum += nums[j];
        res = max(res, rightSum + leftMax[j - 1]);
    }
    return res;
}
