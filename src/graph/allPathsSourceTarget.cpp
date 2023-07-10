#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
void traverse(vector<vector<int>>& graph, int s, vector<int>& path);
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
int main() {
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    allPathsSourceTarget(graph);
    for (auto vec : res) {
        for (auto s : vec) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    traverse(graph, 0, path);
    return res;
}
void traverse(vector<vector<int>>& graph, int s, vector<int>& path) {
    path.emplace_back(s);
    if (s == (int)graph.size() - 1) {
        res.emplace_back(path);
    }
    for (auto neighbor : graph[s]) {
        traverse(graph, neighbor, path);
    }
    path.pop_back();
}