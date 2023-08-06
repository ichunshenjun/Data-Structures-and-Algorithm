#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(m, INT32_MAX));
    for (int i = 0; i < m; i++) {
        graph[i][i] = 0;
    }
    int from, to, dis;
    for (int i = 0; i < n; i++) {
        cin >> from >> to >> dis;
        graph[from - 1][to - 1] = dis;
    }
    int start;
    cin >> start;
    start = start - 1;
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j || j == k) {
                    continue;
                }
                int tmp = (graph[i][k] == INT32_MAX || graph[k][j] == INT32_MAX)
                              ? INT32_MAX
                              : (graph[i][k] + graph[k][k] + graph[k][j]);
                if (graph[i][j] > tmp) {
                    graph[i][j] = tmp;
                }
            }
        }
    }
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (graph[start][i] == INT32_MAX || i == start) continue;
        res = max(res, graph[start][i] + graph[i][i]);
        cnt++;
    }
    cout << cnt + 1 << endl;
    cout << res << endl;
    return 0;
}