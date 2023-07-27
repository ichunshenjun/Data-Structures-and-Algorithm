// 410
#include <iostream>
#include <vector>
using namespace std;
int splitArray(vector<int>& nums, int k);
bool check(vector<int>& nums, long long mid, int days);
int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k) << endl;
    return 0;
}
int splitArray(vector<int>& nums, int k) {
    long long left = 0;
    long long right = INT64_MAX;
    long long res;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(nums, mid, k)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}
bool check(vector<int>& nums, long long mid, int days) {
    int sum = 0;
    int n = nums.size();
    int i = 0;
    int cnt = 0;
    while (i < n) {
        if (sum + nums[i] > mid) {
            if (sum == 0) {
                return false;
            }
            sum = 0;
            cnt++;
        } else {
            sum += nums[i];
            i++;
        }
    }
    if (cnt + 1 > days) {
        return false;
    } else {
        return true;
    }
}