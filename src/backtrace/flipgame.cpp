#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int res = 1000000;
unordered_map<int, int> map;
int flipgame(vector<int>& fronts, vector<int>& backs);
void backtrace(vector<int>& fronts, vector<int>& backs, int start);
int main() {
    vector<int> fronts = {1, 5, 4, 7, 4, 3, 7, 4, 6, 1, 4, 8, 1, 3, 1, 2, 4, 5, 8, 7};
    vector<int> backs = {1, 5, 4, 1, 4, 3, 8, 3, 6, 3, 2, 6, 2, 3, 3, 2, 2, 5, 5, 8};
    flipgame(fronts, backs);
    cout << res;
    return 0;
}
int flipgame(vector<int>& fronts, vector<int>& backs) {
    for (auto front : fronts) {
        map[front]++;
    }
    backtrace(fronts, backs, 0);
    return res == 1000000 ? 0 : res;
}
void backtrace(vector<int>& fronts, vector<int>& backs, int start) {
    for (int i = 0; i < (int)backs.size(); i++) {
        if (map[backs[i]] == 0) {
            res = min(res, backs[i]);
        }
    }
    int len = fronts.size();
    for (int i = start; i < len; i++) {
        int temp = fronts[i];
        fronts[i] = backs[i];
        backs[i] = temp;
        map[temp]--;
        map[fronts[i]]++;
        backtrace(fronts, backs, i + 1);
        temp = fronts[i];
        fronts[i] = backs[i];
        backs[i] = temp;
        map[temp]--;
        map[fronts[i]]++;
    }
}