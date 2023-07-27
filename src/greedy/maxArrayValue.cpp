// 6915
#include <iostream>
#include <vector>
using namespace std;
long long maxArrayValue(vector<int>& nums);
int main() {
    vector<int> nums = {2, 3, 7, 9, 3};
    cout << maxArrayValue(nums) << endl;
    return 0;
}
long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    long long cur = 0;
    cur = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (cur >= nums[i]) {
            cur += nums[i];
        } else {
            cur = nums[i];
        }
    }
    return cur;
}