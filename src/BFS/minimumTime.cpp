// 2050
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);
int main() {
    int n = 3;
    vector<vector<int>> relations = {{1, 3}, {2, 3}};
    vector<int> time = {3, 2, 5};
    cout << minimumTime(n, relations, time);
    return 0;
}
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);
    for (auto relation : relations) {
        indegree[relation[1] - 1]++;
        graph[relation[0] - 1].push_back(relation[1] - 1);
    }
    queue<int> q;
    vector<int> reach(n, 0);
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            reach[i] = max(reach[i], time[i]);
        }
    }
    int res = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int front = q.front();
            q.pop();
            for (auto next : graph[front]) {
                indegree[next]--;
                reach[next] = max(reach[next], reach[front] + time[next]);
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res = max(res, reach[i]);
    }
    return res;
}