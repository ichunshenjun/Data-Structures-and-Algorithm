// 452
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int findMinArrowShots(vector<vector<int>>& points);
int main() {
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points) << endl;
    return 0;
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int minEnd = points[0][1];
    int cnt = 1;
    for (auto point : points) {
        if (point[0] <= minEnd) {
            continue;
        }
        minEnd = point[1];
        cnt++;
    }
    return cnt;
}