#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> path;
vector<vector<int>> paths;
unordered_set<int> bad;
int DFS(vector<vector<int>>& graph, int i);
int main() {
    int n, m, d, x, y, road;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    cin >> d;
    for (int i = 0; i < d; i++) {
        cin >> road;
        graph[road].clear();
        bad.insert(road);
    }
    path.push_back(0);
    int len = DFS(graph, 0);
    vector<int> res;
    for (auto p : paths) {
        if ((int)p.size() == len + 1) {
            if (res.empty()) {
                res = p;
            } else {
                res = min(res, p);
            }
        }
    }
    if (res.empty()) {
        cout << "NULL" << endl;
        return 0;
    }
    for (int i = 0; i < len + 1; i++) {
        if (i != len)
            cout << res[i] << "->";
        else
            cout << res[i] << endl;
    }
    return 0;
}
int DFS(vector<vector<int>>& graph, int i) {
    int res = INT32_MAX / 2;
    if (bad.count(i) == 0 && graph[i].size() == 0) {
        paths.push_back(path);
        return 0;
    }
    for (auto j : graph[i]) {
        path.push_back(j);
        res = min(res, DFS(graph, j) + 1);
        path.pop_back();
    }
    return res;
}