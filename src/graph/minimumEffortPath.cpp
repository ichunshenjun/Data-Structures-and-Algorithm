#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class State {
public:
    int id_;
    int dis_;
    State(int id, int dis) : id_(id), dis_(dis) {}
};
int minimumEffortPath(vector<vector<int>>& heights);
bool judge(vector<vector<int>>& heights, int x, int y);
vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph);
int main() {
    vector<vector<int>> heights = {{4, 3, 4, 10, 5, 5, 9, 2},
                                   {10, 8, 2, 10, 9, 7, 5, 6},
                                   {5, 8, 10, 10, 10, 7, 4, 2},
                                   {5, 1, 3, 1, 1, 3, 1, 9},
                                   {6, 4, 10, 6, 10, 9, 4, 6}};
    cout << minimumEffortPath(heights) << endl;
    return 0;
}
int minimumEffortPath(vector<vector<int>>& heights) {
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<pair<int, int>>> graph(row * col);
    for (int i = 0; i < (int)heights.size(); i++) {
        for (int j = 0; j < (int)heights[0].size(); j++) {
            if (judge(heights, i, j + 1))
                graph[i * col + j].push_back({i * col + j + 1, abs(heights[i][j + 1] - heights[i][j])});
            if (judge(heights, i, j - 1))
                graph[i * col + j].push_back({i * col + j - 1, abs(heights[i][j - 1] - heights[i][j])});
            if (judge(heights, i - 1, j))
                graph[i * col + j].push_back({(i - 1) * col + j, abs(heights[i - 1][j] - heights[i][j])});
            if (judge(heights, i + 1, j))
                graph[i * col + j].push_back({(i + 1) * col + j, abs(heights[i + 1][j] - heights[i][j])});
        }
    }
    auto to = dijkstra(0, graph);
    return to[graph.size() - 1];
}
bool judge(vector<vector<int>>& heights, int x, int y) {
    int row = heights.size();
    int col = heights[0].size();
    if (x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1) {
        return true;
    }
    return false;
}
vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
    vector<int> to(graph.size(), INT32_MAX);
    auto cmp = [](State a, State b) { return a.dis_ > b.dis_; };
    to[start] = 0;
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
    pq.push(State(0, 0));
    while (!pq.empty()) {
        int curID = pq.top().id_;
        int curDis = pq.top().dis_;
        pq.pop();
        if (curID == (int)graph.size() - 1) return to;
        if (to[curID] < curDis) {
            continue;
        }
        for (auto neightbor : graph[curID]) {
            int nextID = neightbor.first;
            int nextDis = max(to[curID], neightbor.second);
            if (nextDis < to[nextID]) {
                to[nextID] = nextDis;
                pq.push(State{nextID, nextDis});
            }
        }
    }
    return to;
}