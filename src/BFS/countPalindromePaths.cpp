// 6942
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
long long countPalindromePaths(vector<int>& parent, string s);
int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "acaabc";
    cout << countPalindromePaths(parent, s) << endl;
    return 0;
}
long long countPalindromePaths(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < (int)parent.size(); i++) {
        if (parent[i] != -1) graph[parent[i]].push_back(i);
    }
    vector<int> patterns(n);
    patterns[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int child : graph[cur]) {
            patterns[child] = patterns[cur] ^ (1 << (s[child] - 'a'));
            q.push(child);
        }
    }
    long long res = 0;
    unordered_map<int, int> patternCount;
    for (int i = 0; i < n; i++) {
        int pattern = patterns[i];
        res += patternCount[pattern];              //计算偶数长度的
        for (int j = 0; j < 26; j++) {             //计算奇数长度的
            int needPattern = pattern ^ (1 << j);  // a^b=c和a^c=b是一样的
            if (patternCount.count(needPattern)) {
                res += patternCount[needPattern];
            }
        }
        patternCount[pattern]++;
    }
    return res;
}