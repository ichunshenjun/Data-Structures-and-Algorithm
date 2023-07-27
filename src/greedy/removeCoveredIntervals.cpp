// 1288
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int removeCoveredIntervals(vector<vector<int>>& intervals);
int main() {
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    cout << removeCoveredIntervals(intervals) << endl;
    return 0;
}
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int i = 0, start = 0, end = 0, n = intervals.size(), cnt = 0;
    while (i < n) {
        if (intervals[i][0] >= start && intervals[i][1] <= end) {
            cnt++;
        } else {
            start = intervals[i][0];
            end = intervals[i][1];
        }
        i++;
    }
    return n - cnt;
}