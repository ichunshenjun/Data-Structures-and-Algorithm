#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int findMaxValueOfEquation(vector<vector<int>>& points, int k);
int main() {
    vector<vector<int>> points = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
    int k = 1;
    cout << findMaxValueOfEquation(points, k) << endl;
    return 0;
}
int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    vector<int> cur;
    deque<pair<int, int>> q;
    int res = INT32_MIN;
    for (auto point : points) {
        int x = point[0];
        int y = point[1];
        while (!q.empty() && abs(x - q.front().first) > k) {
            q.pop_front();
        }
        if (!q.empty()) {
            res = max(res, x + y + q.front().second);
        }
        while (!q.empty() && q.back().second <= y - x) {
            q.pop_back();
        }
        q.push_back({x, y - x});
    }
    return res;
}