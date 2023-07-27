// 174
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> memo;
int calculateMinimumHP(vector<vector<int>>& dungeon);
int dp(vector<vector<int>>& dungeon, int i, int j);
int main() {
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) { return dp(dungeon, 0, 0) + 1; }
int dp(vector<vector<int>>& dungeon, int i, int j) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    if (i >= m || j >= n) {
        return INT32_MAX;
    }
    string key = to_string(i) + ',' + to_string(j);
    if (memo.count(key)) {
        return memo[key];
    }
    if (i == m - 1 && j == n - 1) {
        if (dungeon[i][j] < 0) return -dungeon[i][j];
        return 0;
    }
    int res = max(min(dp(dungeon, i + 1, j), dp(dungeon, i, j + 1)) - dungeon[i][j], 0);
    memo[key] = res;
    return memo[key];
}