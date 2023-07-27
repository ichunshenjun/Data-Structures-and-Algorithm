// 2779
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maximumBeauty(vector<int>& nums, int k);
int main() {
    vector<int> nums = {4, 6, 1, 2};
    int k = 2;
    cout << maximumBeauty(nums, k) << endl;
    return 0;
}
int maximumBeauty(vector<int>& nums, int k) {
    vector<int> begin;
    vector<int> end;
    for (auto num : nums) {
        begin.push_back((num - k));
        end.push_back(num + k);
    }
    sort(begin.begin(), begin.end());
    sort(end.begin(), end.end());
    int count = 0, n = nums.size();
    int res = 0, i = 0, j = 0;
    while (i < n && j < n) {
        if (begin[i] <= end[j]) {
            count++;
            i++;
        } else {
            count--;
            j++;
        }
        res = max(res, count);
    }
    return res;
}