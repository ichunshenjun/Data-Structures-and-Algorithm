// 834 根本想不出来
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int res = 0;
vector<bool> visited;
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges);
void DFS(vector<vector<int>> graph, int i, int dis);
int main() {
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    auto ans = sumOfDistancesInTree(n, edges);
    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        res = 0;
        visited = vector<bool>(n, false);
        DFS(graph, i, 0);
        ans.push_back(res);
    }
    return ans;
}
void DFS(vector<vector<int>> graph, int i, int dis) {
    if (visited[i]) {
        return;
    }
    res += dis;
    visited[i] = true;
    for (auto neighbor : graph[i]) {
        DFS(graph, neighbor, dis + 1);
    }
}