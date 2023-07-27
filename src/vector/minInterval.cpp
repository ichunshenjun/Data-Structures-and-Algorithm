// 1851
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries);
int main() {
    vector<vector<int>> intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    // vector<int> queries = {2,19,5,22};
    vector<int> queries = {2, 3, 4, 5};
    auto res = minInterval(intervals, queries);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    int m = intervals.size();
    int n = queries.size();
    vector<int> indexes(n, 0);
    iota(indexes.begin(), indexes.end(), 0);
    sort(indexes.begin(), indexes.end(), [&](int i, int j) { return queries[i] < queries[j]; });
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
    vector<int> res(n, -1);
    priority_queue<vector<int>> pq;
    int i = 0;
    for (auto index : indexes) {
        while (i < m && queries[index] >= intervals[i][0]) {
            int l = intervals[i][1] - intervals[i][0] + 1;
            pq.push({-l, intervals[i][0], intervals[i][1]});
            i++;
        }
        while (!pq.empty() && queries[index] > pq.top()[2]) {
            pq.pop();
        }
        if (!pq.empty()) {
            res[index] = -pq.top()[0];
        }
    }
    return res;
}