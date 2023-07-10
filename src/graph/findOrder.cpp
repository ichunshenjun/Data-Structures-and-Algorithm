#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int hasCycle = false;
vector<bool> visited;
vector<bool> path;
vector<int> postOrder;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
void traverse(vector<vector<int>>& graph, int s);
int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    findOrder(numCourses, prerequisites);
    return 0;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    visited = vector<bool>(numCourses, false);
    path = vector<bool>(numCourses, false);
    vector<vector<int>> graph(numCourses);
    for (auto vec : prerequisites) {
        graph[vec[1]].emplace_back(vec[0]);
    }
    for (int s = 0; s <= numCourses - 1; s++) {
        traverse(graph, s);
    }
    if (hasCycle) return {};
    reverse(postOrder.begin(), postOrder.end());
    for (auto s : postOrder) {
        cout << s << " ";
    }
    return postOrder;
}
void traverse(vector<vector<int>>& graph, int s) {
    if (path[s]) {
        hasCycle = true;
        return;
    }
    if (visited[s]) {
        return;
    }
    path[s] = true;
    visited[s] = true;
    for (auto neighbor : graph[s]) {
        traverse(graph, neighbor);
    }
    postOrder.push_back(s);
    path[s] = false;
}