#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class State {
public:
    int id;
    int distFromStart;
    State(int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
};
int networkDelayTime(vector<vector<int>>& times, int n, int k);
vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph);
int main() {
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime(times, 4, 2) << endl;
    return 0;
}
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto time : times) {
        graph[time[0]].push_back({time[1], time[2]});
    }
    auto to = dijkstra(k, graph);
    auto res = *max_element(to.begin() + 1, to.end());
    if (res == INT32_MAX) return -1;
    return res;
}
vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
    vector<int> distTo(graph.size(), INT32_MAX);
    distTo[start] = 0;
    auto cmp = [](State a, State b) -> bool { return a.distFromStart > b.distFromStart; };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
    pq.push(State(start, 0));
    while (!pq.empty()) {
        State curState = pq.top();
        pq.pop();
        int curID = curState.id;
        int curDis = curState.distFromStart;
        if (curDis > distTo[curID]) {
            continue;
        }
        for (pair<int, int>& neighbor : graph[curID]) {
            int nextID = neighbor.first;
            int distToNext = distTo[curID] + neighbor.second;
            if (distTo[nextID] > distToNext) {
                distTo[nextID] = distToNext;
                pq.push(State(nextID, distToNext));
            }
        }
    }
    return distTo;
}