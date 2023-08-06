// 2787
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
int numberOfWays(int n, int x);
int backtrace(int n, int x, int i, int sum);
int main() {
    int n = 64, x = 1;
    cout << numberOfWays(n, x) << endl;
    return 0;
}

// int numberOfWays(int n, int x) {
//     visited = vector<bool>(n+1,false);
//     return backtrace(n, x, 0, 0);
// }
// int backtrace(int n, int x, int i, int sum) {
//     int res = 0;
//     if (sum == n) {
//         return 1;
//     }
//     for (int j = i + 1; pow(j, x) <= n; j++) {
//         int delta = pow(j, x);
//         if (sum + delta > n || visited[j]) {
//             continue;
//         }
//         visited[j] = true;
//         sum += delta;
//         res += backtrace(n, x, j, sum);
//         sum -= delta;
//         visited[j] = false;
//     }
//     return res%1000000007;
// }
int numberOfWays(int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= n; w++) {
            if (w - pow(i, x) < 0) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = (dp[i - 1][w - pow(i, x)] + dp[i - 1][w]) % (1000000007);
            }
        }
    }
    return dp[n][n] % (1000000007);
}