// 2681
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int sumOfPower(vector<int>& nums);
int main() {
    vector<int> nums = {2, 1, 4};
    cout << sumOfPower(nums) << endl;
    return 0;
}
int sumOfPower(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> dp(n, 0);
    long long res = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = (nums[i] + sum) % (1000000007);
        sum = (sum + dp[i]) % (1000000007);
        res = (res + ((long long)nums[i] * nums[i]) % (1000000007) * dp[i]) % (1000000007);
    }
    return res % (1000000007);
}