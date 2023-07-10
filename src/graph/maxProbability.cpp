#include <ios>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct State {
    int id;
    double dis;
    State(int id, double dis) : id(id), dis(dis) {}
};
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end);
double dijkstra(int n, int start, int end, vector<vector<pair<int, double>>>& graph);
int main() {
    int n = 5;
    // vector<vector<int>> edges = {{0, 1}};
    vector<vector<int>> edges = {{1, 4}, {2, 4}, {0, 4}, {0, 3}, {0, 2}, {2, 3}};
    vector<double> succProb = {0.37, 0.17, 0.93, 0.23, 0.39, 0.04};
    int start = 3, end = 4;
    cout << maxProbability(n, edges, succProb, start, end) << endl;
    return 0;
}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < (int)edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
        graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    double res = dijkstra(n, start, end, graph);
    return res;
}
double dijkstra(int n, int start, int end, vector<vector<pair<int, double>>>& graph) {
    vector<double> to(n, 0);
    auto cmp = [](State a, State b) { return a.dis < b.dis; };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
    to[start] = 1;
    pq.push(State{start, 1});
    while (!pq.empty()) {
        int curID = pq.top().id;
        double curDis = pq.top().dis;
        pq.pop();
        if (curID == end) return curDis;
        if (curDis > to[curID]) {
            continue;
        }
        for (auto neighbor : graph[curID]) {
            int nextID = neighbor.first;
            double nextDis = to[curID] * neighbor.second;
            if (nextDis > to[nextID]) {
                to[nextID] = nextDis;
                pq.push(State{nextID, nextDis});
            }
        }
    }
    return to[end];
}