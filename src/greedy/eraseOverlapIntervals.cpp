// 435
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals);
int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int minEnd = intervals[0][1];
    int cnt = 0;
    for (auto interval : intervals) {
        if (interval[0] < minEnd) {
            cnt++;
            continue;
        }
        minEnd = interval[1];
    }
    return --cnt;
}