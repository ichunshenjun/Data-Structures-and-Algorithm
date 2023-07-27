// 2780
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int minimumIndex(vector<int>& nums);
int main() {
    vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    cout << minimumIndex(nums) << endl;
    return 0;
}
int minimumIndex(vector<int>& nums) {
    unordered_map<int, int> map;
    int n = nums.size();
    int num = 0;
    for (auto num : nums) {
        map[num]++;
    }
    for (auto itr = map.begin(); itr != map.end(); itr++) {
        if (itr->second * 2 > n) {
            num = itr->first;
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == num) {
            cnt++;
        }
        if (cnt * 2 > i + 1 && (map[num] - cnt) * 2 > n - i - 1) {
            return i;
        }
    }
    return -1;
}