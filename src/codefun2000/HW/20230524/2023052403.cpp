#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<int>> dp;

void dfs(int u) {
    int left = u * 2 + 1;
    int right = u * 2 + 2;
    if (left >= (int)arr.size()) {  //如果是叶子节点,求到dp后直接return
        dp[u][0] = 0;
        dp[u][1] = arr[u];
        return;
    }
    dfs(left);   //非叶子节点,就要先求到左子树的最大维护成本
    dfs(right);  //和右子树的最大维护成本
    dp[u][0] = max(dp[left][0], dp[left][1]) + max(dp[right][0], dp[right][1]);  //如果我们不撤销u
    dp[u][1] = dp[left][0] + dp[right][0] + arr[u];                              //如果我们撤销u
}

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp.resize(n, vector<int>(2));  //处理输入

    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}