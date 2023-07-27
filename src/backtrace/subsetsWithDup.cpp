// 90
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<vector<int>> subsetsWithDup(vector<int>& nums);
void backtrace(vector<int>& nums, int start, vector<int>& path);
int main() {
    vector<int> nums = {1, 2, 3};
    subsetsWithDup(nums);
    return 0;
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> path;
    sort(nums.begin(), nums.end());
    res.push_back({});
    backtrace(nums, 0, path);
    return res;
}
void backtrace(vector<int>& nums, int start, vector<int>& path) {
    for (int i = start; i < (int)nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        path.push_back(nums[i]);
        res.push_back(path);
        backtrace(nums, i + 1, path);
        path.pop_back();
    }
}