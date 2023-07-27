// 40
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<vector<int>> res;
unordered_set<int> set;
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
void backtrace(vector<int>& candidates, int start, int target, int sum, vector<int>& path);
int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    combinationSum2(candidates, target);
    return 0;
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> path;
    sort(candidates.begin(), candidates.end());
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
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtrace(candidates, i + 1, target, sum, path);
        sum -= candidates[i];
        path.pop_back();
    }
}