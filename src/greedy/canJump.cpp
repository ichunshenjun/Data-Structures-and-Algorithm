// 55
#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums);
int main() {
    vector<int> nums = {2, 3, 1, 0, 4};
    cout << canJump(nums) << endl;
    return 0;
}
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int far = 0;
    for (int i = 0; i < n - 1; i++) {
        far = max(far, i + nums[i]);
        if (far <= i) {
            return false;
        }
    }
    return far >= n - 1;
}