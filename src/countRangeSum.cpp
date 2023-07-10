#include <iostream>
#include <vector>
using namespace std;
vector<long> temp;
vector<long> preSum;
int res = 0;
int lower = -564, upper = 3864;
int countRangeSum(vector<long>& nums, int lower, int upper);
void sort(vector<long>& nums, int left, int right);
void merge(vector<long>& nums, int left, int mid, int right);
int main() {
    vector<long> nums = {-2147483647, 0, -2147483647, 2147483647};
    countRangeSum(nums, lower, upper);
    cout << res << endl;
    return 0;
}
int countRangeSum(vector<long>& nums, int lower, int upper) {
    temp.resize(nums.size() + 1);
    preSum.resize(nums.size() + 1);
    preSum[0] = 0;
    for (int i = 1; i < (int)preSum.size(); i++) preSum[i] = preSum[i - 1] + nums[i - 1];
    sort(preSum, 0, preSum.size() - 1);
    return 0;
}
void sort(vector<long>& nums, int left, int right) {
    if (left == right) return;
    int mid = left + (right - left) / 2;
    sort(nums, left, mid);
    sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}
void merge(vector<long>& nums, int left, int mid, int right) {
    for (int i = left; i <= right; i++) {
        temp[i] = nums[i];
    }
    int l = mid + 1, r = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (l <= right && nums[l] - nums[i] < lower) l++;
        while (r <= right && nums[r] - nums[i] <= upper) r++;
        res += r - l;
    }
    int i = left, j = mid + 1;
    for (int p = left; p <= right; p++) {
        if (i == mid + 1) {
            nums[p] = temp[j++];
        } else if (j == right + 1) {
            nums[p] = temp[i++];
        } else if (temp[i] < temp[j]) {
            nums[p] = temp[i++];
        } else {
            nums[p] = temp[j++];
        }
    }
}