// 216
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<vector<int>> res;
unordered_set<int> set;
vector<vector<int>> combinationSum3(int k, int n);
void backtrace(int k, int n, int visited, int sum, int num, vector<int>& path);
int main() {
    int k = 3, n = 9;
    combinationSum3(k, n);
    return 0;
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path;
    backtrace(k, n, 0, 0, 0, path);
    return res;
}
void backtrace(int k, int n, int visited, int sum, int num, vector<int>& path) {
    if (sum == n && num == k) {
        if (set.count(visited) == 0) {
            res.push_back(path);
        }
        set.insert(visited);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (((visited >> i) & 1) == 1) {
            continue;
        }
        if (sum + i > n) {
            continue;
        }
        visited |= 1 << i;
        path.push_back(i);
        sum = sum + i;
        num = num + 1;
        backtrace(k, n, visited, sum, num, path);
        sum = sum - i;
        num = num - 1;
        visited ^= 1 << i;
        path.pop_back();
    }
}