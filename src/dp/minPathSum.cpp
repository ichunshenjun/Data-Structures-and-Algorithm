#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> memo;
int minPathSum(vector<vector<int>>& grid);
int dp(vector<vector<int>>& grid, int i, int j);
int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    return 0;
}
int minPathSum(vector<vector<int>>& grid) { return dp(grid, 0, 0); }
int dp(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    if (i >= m || j >= n) {
        return INT32_MAX;
    }
    if (i == m - 1 && j == n - 1) {
        return grid[i][j];
    }
    string key = to_string(i) + ',' + to_string(j);
    if (memo.count(key)) {
        return memo[key];
    }
    int res = 0;
    res = min(dp(grid, i + 1, j), dp(grid, i, j + 1)) + grid[i][j];
    memo[key] = res;
    return res;
}