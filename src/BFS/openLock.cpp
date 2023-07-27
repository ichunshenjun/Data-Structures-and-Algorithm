// 752
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
int openLock(vector<string>& deadends, string target);
int main() {
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    openLock(deadends, target);
    return 0;
}
int openLock(vector<string>& deadends, string target) {
    int res = 0;
    unordered_set<string> set;
    unordered_set<string> visited;
    for (auto deadend : deadends) set.emplace(deadend);
    queue<string> q;
    if (set.count("0000") == 0) {
        q.push("0000");
        visited.insert("0000");
    }
    while (!q.empty()) {
        int sz = q.size();
        for (int j = 0; j < sz; j++) {
            string str = q.front();
            q.pop();
            if (str == target) {
                return res;
            }
            for (int i = 0; i < 4; i++) {
                string temp = str;
                temp[i] = str[i] == '9' ? '0' : str[i] + 1;
                if (set.count(temp) == 0 && visited.count(temp) == 0) {
                    q.push(temp);
                    visited.insert(temp);
                }
                temp[i] = str[i] == '0' ? '9' : str[i] - 1;
                if (set.count(temp) == 0 && visited.count(temp) == 0) {
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }
        res++;
    }
    return -1;
}
