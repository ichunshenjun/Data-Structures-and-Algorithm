#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x, y;
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            continue;
        }
        for (int j = 0; j < x; j++) {
            cin >> y;
            graph[i].push_back(y - 1);
            indegree[y - 1]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        level++;
        for (int i = 0; i < sz; i++) {
            int cur = q.front();
            q.pop();
            count++;
            for (auto next : graph[cur]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
    if (count != n) {
        cout << -1 << endl;
    }
    cout << level << endl;
    return 0;
}