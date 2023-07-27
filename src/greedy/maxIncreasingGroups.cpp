// 6955
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool check(vector<int>& usageLimits, int m);
int maxIncreasingGroups(vector<int>& usageLimits);
int main() {
    vector<int> usageLimits = {1, 2, 5};
    cout << maxIncreasingGroups(usageLimits) << endl;
    return 0;
}
int maxIncreasingGroups(vector<int>& usageLimits) {
    int n = usageLimits.size();
    long long cur = 0;
    int cnt = 1;
    sort(usageLimits.begin(), usageLimits.end());
    for (int i = 0; i < n; i++) {
        if (cur + usageLimits[i] >= cnt) {
            cur = cur + usageLimits[i] - cnt;
            cnt++;
        } else {
            cur = cur + usageLimits[i];
        }
    }
    return cnt - 1;
}