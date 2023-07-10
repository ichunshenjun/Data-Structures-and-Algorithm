#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
vector<bool> color;
bool ok = true;
bool possibleBipartition(int n, vector<vector<int>>& dislikes);
void DFS(vector<vector<int>>& graph, int s);
int main() {
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
    int n = 4;
    cout << possibleBipartition(n, dislikes);
    return 0;
}
bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n);
    for (auto vec : dislikes) {
        graph[vec[1] - 1].emplace_back(vec[0] - 1);
        graph[vec[0] - 1].emplace_back(vec[1] - 1);
    }
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