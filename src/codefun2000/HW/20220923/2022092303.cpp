#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// vector<int> path;
vector<vector<bool>> edge;
vector<vector<int>> memo;
int dp(vector<vector<int>>& graph, int city, int visited);
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    edge = vector<vector<bool>>(n, vector<bool>(n, false));
    memo = vector<vector<int>>(n, vector<int>(1 << n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    // path.push_back(0);
    int res = dp(graph, 0, 0);
    cout << res << endl;
    return 0;
}
int dp(vector<vector<int>>& graph, int city, int visited) {
    int res = INT32_MAX / 2;
    int n = graph.size();
    visited |= 1 << city;
    if (memo[city][visited] != -1) {
        return memo[city][visited];
    }
    if (city == 0 && visited == ((1 << n) - 1)) {
        // for(auto num:path){
        //     cout<<num<<" ";
        // }
        // cout<<endl;
        memo[city][visited] = 0;
        return 0;
    } else if (city == 0 && visited != 1) {
        memo[city][visited] = INT32_MAX / 2;
        return INT32_MAX / 2;
    }
    for (int i = 0; i < n; i++) {
        if (i != city && !edge[city][i]) {
            edge[city][i] = true;  //防止走重复的路径
            // path.push_back(i);
            res = min(res, dp(graph, i, visited) + graph[city][i]);
            // path.pop_back();
            // if(city==0){
            //     cout<<"res "<<res<<endl;
            // }
            edge[city][i] = false;
        }
    }
    memo[city][visited] = res;
    return res;
}