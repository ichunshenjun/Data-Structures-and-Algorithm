// 78
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<bool> visited;
vector<vector<int>> subsets(vector<int>& nums);
void backtrace(vector<int>& nums, int start, vector<int>& path);
int main() {
    vector<int> nums = {1, 2, 3};
    subsets(nums);
    return 0;
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    visited = vector<bool>(nums.size(), false);
    res.push_back({});
    backtrace(nums, 0, path);
    return res;
}
void backtrace(vector<int>& nums, int start, vector<int>& path) {
    for (int i = start; i < (int)nums.size(); i++) {
        if (visited[i]) {
            continue;
        }
        path.push_back(nums[i]);
        res.push_back(path);
        visited[i] = true;
        backtrace(nums, i + 1, path);
        path.pop_back();
        visited[i] = false;
    }
}