// 77
#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;
vector<vector<int>> res;
vector<vector<int>> combine(int n, int k);
void backtrace(int n, int k, int start, vector<int>& path);
int main() {
    int n = 4, k = 2;
    combine(n, k);
    return 0;
}
vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    visited = vector<int>(n + 1, false);
    backtrace(n, k, 1, path);
    return res;
}
void backtrace(int n, int k, int start, vector<int>& path) {
    if (k == 0) {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        k = k - 1;
        visited[i] = true;
        path.push_back(i);
        backtrace(n, k, i + 1, path);
        path.pop_back();
        visited[i] = false;
        k = k + 1;
    }
}