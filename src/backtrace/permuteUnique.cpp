// 47
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<int> path;
vector<bool> visited;
vector<vector<int>> permuteUnique(vector<int>& nums);
void backtrace(vector<int>& nums);
int main() {
    vector<int> nums = {1, 2, 3};
    permuteUnique(nums);
    return 0;
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    visited = vector<bool>(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrace(nums);
    return res;
}
void backtrace(vector<int>& nums) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < (int)nums.size(); i++) {
        if (visited[i]) {
            continue;
        }
        // 剪枝逻辑，固定相同的元素在排列中的相对位置
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
            continue;
        }
        visited[i] = true;
        path.push_back(nums[i]);
        backtrace(nums);
        path.pop_back();
        visited[i] = false;
    }
}