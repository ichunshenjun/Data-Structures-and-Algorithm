// 1012
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
int numDupDigitsAtMostN(int n);
int f(int mask, string& sn, int i, bool same);
int main() {
    int n = 20;
    cout << numDupDigitsAtMostN(n);
    return 0;
}
int numDupDigitsAtMostN(int n) {
    string sn = to_string(n);
    dp = vector<vector<int>>(sn.size(), vector<int>(1 << 10, -1));
    return n + 1 - f(0, sn, 0, true);
}
int f(int mask, string& sn, int i, bool same) {
    if (i == (int)sn.size()) {
        return 1;
    }
    if (!same && dp[i][mask] >= 0) {
        return dp[i][mask];
    }
    int res = 0, t = same ? (sn[i] - '0') : 9;
    for (int k = 0; k <= t; k++) {
        if (mask & (1 << k)) {
            continue;
        }
        res += f(mask == 0 && k == 0 ? mask : mask | (1 << k), sn, i + 1, same && k == t);
    }
    if (!same) {
        dp[i][mask] = res;
    }
    return res;
}