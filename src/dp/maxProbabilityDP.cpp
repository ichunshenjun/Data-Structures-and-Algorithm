// 1514
// 用dp是做不出来的可以看评论区有篇文章，像这种无向图都很难处理
#include <iostream>
#include <vector>
using namespace std;
struct State {
    int id;
    double dis;
    State(int id, double dis) : id(id), dis(dis){};
};
vector<bool> visited;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end);
double dp(vector<vector<State>>& graph, int start, int end, int arr);
int main() {
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    cout << maxProbability(n, edges, succProb, start, end) << endl;
    return 0;
}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<State>> graph(n);
    visited = vector<bool>(n, false);
    for (int i = 0; i < (int)edges.size(); i++) {
        graph[edges[i][0]].push_back(State{edges[i][1], succProb[i]});
        graph[edges[i][1]].push_back(State{edges[i][0], succProb[i]});
    }
    return dp(graph, start, end, end);
}
double dp(vector<vector<State>>& graph, int start, int end, int arr) {
    if (arr == start) {
        return 1;
    }
    double res = 0;
    if (visited[arr]) return 0;
    for (auto edge : graph[arr]) {
        visited[edge.id] = true;
        res = max(res, dp(graph, start, end, edge.id) * edge.dis);
        visited[edge.id] = false;
    }
    return res;
}