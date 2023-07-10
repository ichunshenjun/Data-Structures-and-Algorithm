#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int res = 0;
int reversePairs(vector<int>& nums);
void sort(vector<int>& nums, int left, int right);
void merge(vector<int>& nums, int left, int mid, int right);
int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    reversePairs(nums);
    cout << res << endl;
}
int reversePairs(vector<int>& nums) {
    arr.resize(nums.size());
    sort(nums, 0, nums.size() - 1);
    return res;
}
void sort(vector<int>& nums, int left, int right) {
    if (left == right) return;
    int mid = left + (right - left) / 2;
    sort(nums, left, mid);
    sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}
void merge(vector<int>& nums, int left, int mid, int right) {
    for (int i = left; i <= right; i++) {
        arr[i] = nums[i];
    }
    int i = left, j = mid + 1;
    for (j = mid + 1; j <= right; j++)
        for (; i <= mid; i++) {
            if (arr[i] > 2 * arr[j]) {
                res += mid - i + 1;
                break;
            }
        }
    i = left, j = mid + 1;
    for (int p = left; p <= right; p++) {
        if (i == mid + 1) {
            nums[p] = arr[j++];
        } else if (j == right + 1) {
            nums[p] = arr[i++];
        } else if (arr[i] <= arr[j]) {
            nums[p] = arr[i++];
        } else if (arr[i] > arr[j]) {
            nums[p] = arr[j++];
        }
    }
}