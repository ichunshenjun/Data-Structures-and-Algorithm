// 862
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int shortestSubarray(vector<int>& nums, int k);
int main() {
    vector<int> nums = {2, -1, 2};
    int k = 3;
    shortestSubarray(nums, k);
    return 0;
}
int shortestSubarray(vector<int>& nums, int k) {
    int res = nums.size() + 1;
    vector<long> preSum(nums.size() + 1, 0);
    for (int i = 1; i < (int)preSum.size(); i++) preSum[i] = preSum[i - 1] + nums[i - 1];
    deque<int> q;
    for (int i = 0; i < (int)preSum.size(); i++) {
        long cur = preSum[i];
        while (!q.empty() && cur - preSum[q.front()] >= k) {
            res = min(res, i - q.front());
            q.pop_front();
        }
        while (!q.empty() && cur <= preSum[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    return res == (int)nums.size() + 1 ? -1 : res;
}