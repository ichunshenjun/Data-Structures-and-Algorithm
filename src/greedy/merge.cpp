// 56
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals);
int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    merge(intervals);
    return 0;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int start = -1, end = -1, i = 0, n = intervals.size();
    while (i < n) {
        if (intervals[i][0] > end) {
            if (start != -1 && end != -1) res.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
            i++;
            if (i == n) {
                res.push_back({start, end});
            }
            continue;
        }
        if (intervals[i][1] > end) {
            end = intervals[i][1];
        }
        i++;
        if (i == n) {
            res.push_back({start, end});
        }
    }
    return res;
}