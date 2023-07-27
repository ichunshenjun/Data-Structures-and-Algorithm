#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k);
int main() {
    vector<int> nums = {1, -1};
    int k = 1;
    auto res = maxSlidingWindow(nums, k);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> res;
//     priority_queue<int, vector<int>> pq;
//     vector<int>::iterator itr = nums.begin();
//     unordered_map<int, int> window;
//     for (auto num : nums) {
//         pq.push(num);
//         window[num]++;
//         if ((int)pq.size() == k) {
//             res.emplace_back(pq.top());
//         } else if ((int)pq.size() > k) {
//             window[*itr]--;
//             itr++;
//             while (window[pq.top()] == 0) {
//                 pq.pop();
//             }
//             res.emplace_back(pq.top());
//         }
//     }
//     if ((int)pq.size() < k) res.emplace_back(pq.top());
//     return res;
// }
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    res.push_back(nums[q.front()]);
    for (int i = k; i < (int)nums.size(); i++) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        while (!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        q.push_back(i);
        res.push_back(nums[q.front()]);
    }
    return res;
}