// 46
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<int> path;
vector<bool> visited;
vector<vector<int>> permute(vector<int>& nums);
void backtrace(vector<int>& nums);
int main() {
    vector<int> nums = {1, 2, 3};
    permute(nums);
    return 0;
}
vector<vector<int>> permute(vector<int>& nums) {
    visited = vector<bool>(nums.size(), false);
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
        visited[i] = true;
        path.push_back(nums[i]);
        backtrace(nums);
        path.pop_back();
        visited[i] = false;
    }
}