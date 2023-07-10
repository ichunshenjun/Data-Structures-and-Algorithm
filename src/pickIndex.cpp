#include <iostream>
#include <vector>
using namespace std;
int pickIndex();
vector<int> w = {1, 3};
int main() {
    auto res = pickIndex();
    cout << res << endl;
    return 0;
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
            left = mid + 1;
        }
    }
    if (nums[left - 1] == target) {
        return left - 1;
    }
    return left;
}
int pickIndex() {
    vector<int> preSum;
    preSum.resize(w.size() + 1);
    preSum[0] = 0;
    for (size_t i = 1; i <= w.size(); i++) {
        preSum[i] = preSum[i - 1] + w[i - 1];
    }
    int n = preSum.size();
    int target = rand() % preSum[n - 1] + 1;
    int ans = binarySearch(preSum, target);
    cout << target << " " << ans << endl;
    return ans - 1;
}