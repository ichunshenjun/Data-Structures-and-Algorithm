// 2439
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> nums, int mid) {
    long long gap = 0;
    for (int i = nums.size() - 1; i >= 1; i--) {
        gap = max(nums[i] - mid + gap, (long long)0);
    }
    if (nums[0] + gap > mid) {
        return false;
    }
    return true;
}
int minimizeArrayValue(vector<int>& nums) {
    int left = 0, right = *max_element(nums.begin(), nums.end());
    int res;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(nums, mid)) {
            res = mid;
            right = mid - 1;
        } else
            left = mid + 1;
    }
    return res;
}
int main() {
    vector<int> nums = {3, 7, 1, 6};
    cout << minimizeArrayValue(nums) << endl;
    return 0;
}