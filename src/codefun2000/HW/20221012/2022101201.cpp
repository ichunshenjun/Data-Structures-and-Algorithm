#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
int findLongeststr(string& a, string& b);
int dp(string& a, int i, string& b, int j);
int main() {
    string a, b;
    cin >> a >> b;
    cout << findLongeststr(a, b) << endl;
    return 0;
}
int findLongeststr(string& a, string& b) {
    int m = a.size(), n = b.size();
    if (m == 0 || n == 0) {
        return 0;
    }
    memo = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));
    int res = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            res = max(res, dp(a, i, b, j));
        }
    }
    return res;
}
int dp(string& a, int i, string& b, int j) {
    if (i == -1 || j == -1) {
        return 0;
    }
    if (memo[i][j] != -1) return memo[i][j];
    if (a[i] == b[j]) {
        memo[i][j] = dp(a, i - 1, b, j - 1) + 1;
    } else {
        return 0;
    }
    return memo[i][j];
}