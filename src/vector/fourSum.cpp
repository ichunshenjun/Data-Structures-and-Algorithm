// 18
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target);
vector<vector<int>> nSum(vector<int>& nums, int n, int start, long target);
int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto res = fourSum(nums, target);
    return 0;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    res = nSum(nums, 4, 0, target);
    return res;
}
vector<vector<int>> nSum(vector<int>& nums, int n, int start, long target) {
    int sz = nums.size();
    vector<vector<int>> res;
    if (n < 2 || sz < n) return res;
    if (n == 2) {
        int left = start, right = sz - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            int lnum = nums[left];
            int rnum = nums[right];
            if (sum < target) {
                while (left < right && nums[left] == lnum) left++;
            }
            if (sum > target) {
                while (left < right && nums[right] == rnum) right--;
            }
            if (sum == target) {
                res.push_back({lnum, rnum});
                while (left < right && nums[left] == lnum) left++;
                while (left < right && nums[right] == rnum) right--;
            }
        }
    } else {
        for (int i = start; i < sz; i++) {
            vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
            for (vector<int>& arr : sub) {
                arr.push_back(nums[i]);
                res.push_back(arr);
            }
            while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    return res;
}