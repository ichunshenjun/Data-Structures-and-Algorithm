#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums);
int main() {
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int res = lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    dp[0] = 1;
    for (int i = 1; i < (int)dp.size(); i++) {
        int j = 0;
        for (j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (j == -1 && dp[i] == 1) {
            dp[i] = 1;
        }
    }
    return *max_element(dp.begin(), dp.end());
}