#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int robot(vector<int>& starts, vector<int>& ends);
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> classes;
    int maxn = 0;
    int minn = INT32_MAX;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        classes.push_back({start, end});
        maxn = max(maxn, end);
        minn = min(minn, start);
    }
    vector<int> diff(maxn + 2, 0);
    for (auto num : classes) {
        diff[num.first]++;
        diff[num.second + 1]--;
    }
    vector<int> nums(maxn + 2, 0);
    nums[0] = diff[0];
    for (int i = 1; i < maxn + 2; i++) {
        nums[i] = nums[i - 1] + diff[i];
    }
    for (int i = minn; i <= maxn; i++) {
        if (nums[i] >= 2) {
            res += 4;
        } else if (nums[i] == 0) {
            res += 1;
        } else if (nums[i] == 1) {
            res += 3;
        }
    }
    cout << res << endl;
    return 0;
}
