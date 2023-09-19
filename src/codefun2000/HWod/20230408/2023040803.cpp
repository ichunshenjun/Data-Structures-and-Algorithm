#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int N;
    int x;
    vector<int> nums;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        nums.push_back(x);
    }
    unordered_map<int, vector<pair<int, int>>> map;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += nums[j];
            map[sum].push_back({i, j});
        }
    }
    int res = 0;
    ;
    for (auto itr = map.begin(); itr != map.end(); itr++) {
        vector<pair<int, int>> intervals = itr->second;
        if ((int)intervals.size() <= res) {
            continue;
        }
        sort(intervals.begin(), intervals.end(),
             [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        int cnt = 1;
        auto cur = intervals[0];
        for (int i = 0; i < (int)intervals.size(); i++) {
            if (intervals[i].first > cur.second) {
                cur = intervals[i];
                cnt++;
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}