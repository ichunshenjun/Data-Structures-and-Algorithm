#include <iostream>
#include <vector>
using namespace std;
string s;
int res = 0;
bool DFS(vector<vector<int>>& graph, int root);
int main() {
    int n;
    cin >> n;
    cin >> s;
    vector<vector<int>> graph(n);
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }
    DFS(graph, 0);
    cout << res;
    return 0;
}
bool DFS(vector<vector<int>>& graph, int root) {
    bool flag = s[root] == 'R';
    for (auto neighbor : graph[root]) {
        bool temp = DFS(graph, neighbor);
        flag = flag && temp;
    }
    if (flag == true) {
        res++;
    }
    return flag;
}