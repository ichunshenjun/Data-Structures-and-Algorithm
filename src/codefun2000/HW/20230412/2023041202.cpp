#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
vector<int> values;
int res = INT32_MIN;
int maxFood(vector<vector<int>>& graph);
void DFS(vector<vector<int>>& graph, int i, int value);
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    values = vector<int>(n);
    for (int i = 0; i < n; i++) {
        int id, parent, value;
        cin >> id >> parent >> value;
        if (parent != -1) graph[parent].push_back(id);
        values[id] = value;
    }
    cout << maxFood(graph) << endl;
    return 0;
}
int maxFood(vector<vector<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        DFS(graph, i, 0);
    }
    return res;
}
void DFS(vector<vector<int>>& graph, int i, int value) {
    value += values[i];
    res = max(res, value);
    for (auto edge : graph[i]) {
        DFS(graph, edge, value);
    }
}