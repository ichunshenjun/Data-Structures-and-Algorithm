#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
vector<bool> path;
bool flag = true;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
void traverse(vector<vector<int>>& graph, int s);
int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << canFinish(numCourses, prerequisites);
    return 0;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    visited = vector<bool>(numCourses, false);
    path = vector<bool>(numCourses, false);
    vector<vector<int>> graph(numCourses);
    for (auto vec : prerequisites) {
        graph[vec[1]].emplace_back(vec[0]);
    }
    for (int s = 0; s <= numCourses - 1; s++) {
        traverse(graph, s);
    }
    return flag;
}
void traverse(vector<vector<int>>& graph, int s) {
    if (path[s]) {
        flag = false;
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
    path[s] = false;
}