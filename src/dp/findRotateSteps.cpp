// 514
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<char, vector<int>> map;
unordered_map<string, int> memo;
int findRotateSteps(string ring, string key);
int dp(string& ring, int i, string& key, int j);
int main() {
    string ring = "godding", key = "gd";
    cout << findRotateSteps(ring, key) << endl;
    return 0;
}
int findRotateSteps(string ring, string key) {
    for (int i = 0; i < (int)ring.size(); i++) map[ring[i]].push_back(i);
    return dp(ring, 0, key, 0);
}
int dp(string& ring, int i, string& key, int j) {
    string s = to_string(i) + "," + to_string(j);
    if (j == (int)key.size()) return 0;
    if (memo.count(s)) {
        return memo[s];
    }
    int n = ring.size();
    int res = INT32_MAX;
    for (auto index : map[key[j]]) {
        int order = abs(i - index);
        order = min(order, n - order);
        int subProblem = dp(ring, index, key, j + 1);
        res = min(res, order + subProblem + 1);
    }
    memo[s] = res;
    return res;
}