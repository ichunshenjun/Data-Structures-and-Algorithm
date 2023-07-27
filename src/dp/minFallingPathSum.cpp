// 931
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int minFallingPathSum(vector<vector<int>>& matrix);
int main() {
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                dp[i][j] = matrix[i][j];
                continue;
            }
            int a = INT32_MAX, b = INT32_MAX, c = INT32_MAX;
            if (j - 1 >= 0) a = dp[i - 1][j - 1];
            if (j + 1 < n) c = dp[i - 1][j + 1];
            b = dp[i - 1][j];
            dp[i][j] = min(min(a, b), c) + matrix[i][j];
        }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
}