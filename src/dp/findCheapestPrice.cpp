// 787
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
    int x;
    int cost;
    Node(int x, int cost) : x(x), cost(cost){};
};
unordered_map<string, long> memo;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k);
long dp(vector<vector<Node>>& graph, int src, int dst, int arr, int k);
int main() {
    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<Node>> graph(n);
    for (auto flight : flights) {
        graph[flight[1]].emplace_back(Node{flight[0], flight[2]});
    }
    long res = dp(graph, src, dst, dst, k);
    return res == INT32_MAX ? -1 : res;
}
long dp(vector<vector<Node>>& graph, int src, int dst, int arr, int k) {
    if (arr == src) {
        if (k >= -1)
            return 0;
        else
            return INT32_MAX;
    }
    if (k < -1) {
        return INT32_MAX;
    }
    string key = to_string(arr) + "," + to_string(k);
    if (memo.count(key)) {
        return memo[key];
    }
    long res = INT32_MAX;
    for (auto edge : graph[arr]) {
        res = min(res, dp(graph, src, dst, edge.x, k - 1) + edge.cost);
    }
    memo[key] = res;
    return res;
}