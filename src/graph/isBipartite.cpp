#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
vector<bool> color;
bool ok = true;
bool isBipartite(vector<vector<int>>& graph);
void DFS(vector<vector<int>>& graph, int s);
int main() {
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << isBipartite(graph);
    return 0;
}
bool isBipartite(vector<vector<int>>& graph) {
    visited = vector<bool>(graph.size(), false);
    color = vector<bool>(graph.size(), false);
    for (int s = 0; s < (int)graph.size(); s++) {
        if (!visited[s]) DFS(graph, s);
    }
    return ok;
}
void DFS(vector<vector<int>>& graph, int s) {
    if (!ok) return;
    visited[s] = true;
    for (auto neighbor : graph[s]) {
        if (!visited[neighbor]) {
            color[neighbor] = !color[s];
            DFS(graph, neighbor);
        } else {
            if (color[neighbor] == color[s]) {
                ok = false;
                return;
            }
        }
    }
}