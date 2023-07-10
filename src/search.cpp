#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int target);
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    auto res = search(nums, target);
    cout << res << endl;
    return 0;
}
int search(vector<int>& nums, int target) {
    int left = binarySearch(nums, target);
    int right = binarySearch(nums, target + 1);
    if (left == static_cast<int>(nums.size()) || nums[left] != target) {
        return 0;
    }
    return right - 1 - left + 1;
}
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        if (nums[mid] > target) {
            right = mid - 1;
        }
        if (nums[mid] == target) {
            right = mid - 1;
        }
    }
    return left;
}