#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, R, M;
    cin >> N >> R >> M;
    int k;
    vector<pair<int, int>> intervals;
    while (scanf("%d", &k) != EOF) {
        intervals.push_back({k - R, k + R});
    }
    sort(intervals.begin(), intervals.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; });
    int sz = intervals.size();
    int target = 0;
    int i = 0;
    int find;
    int cnt = 0;
    int last = 0;
    while (i < sz && target < N) {
        if (intervals[i].first <= target) {
            find = i;
            last = find;
            i++;
        } else {
            if (find == -1) {
                cout << -1 << endl;
                return 0;
            }
            target = intervals[find].second;
            cnt++;
            find = -1;
        }
    }
    if (last == sz - 1) {
        cnt++;
    }
    if (intervals[last].second < N) {
        cout << -1 << endl;
        return 0;
    }
    cout << (long long)cnt * M << endl;
    return 0;
}