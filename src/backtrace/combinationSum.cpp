// 39
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<vector<int>> res;
unordered_set<int> set;
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void backtrace(vector<int>& candidates, int start, int target, int sum, vector<int>& path);
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    combinationSum(candidates, target);
    return 0;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    backtrace(candidates, 0, target, 0, path);
    return res;
}
void backtrace(vector<int>& candidates, int start, int target, int sum, vector<int>& path) {
    if (sum == target) {
        res.emplace_back(path);
        return;
    }
    for (int i = start; i < (int)candidates.size(); i++) {
        if (sum + candidates[i] > target) {
            continue;
        }
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtrace(candidates, i, target, sum, path);
        sum -= candidates[i];
        path.pop_back();
    }
}