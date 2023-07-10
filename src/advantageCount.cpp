#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2);
int main() {
    vector<int> nums1 = {2, 0, 4, 1, 2};
    vector<int> nums2 = {1, 3, 0, 0, 2};
    auto res = advantageCount(nums1, nums2);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const { return a.second > b.second; }
};
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    vector<pair<int, int>> vec2;
    vector<int> res;
    sort(nums1.begin(), nums1.end(), [](int a, int b) { return a < b; });
    res.resize(nums1.size());
    for (int i = 0; i < static_cast<int>(nums2.size()); i++) {
        vec2.emplace_back(make_pair(i, nums2[i]));
    }
    sort(vec2.begin(), vec2.end(), cmp());
    int left = 0, right = nums1.size() - 1;
    for (auto itr = vec2.begin(); itr != vec2.end(); itr++) {
        if (nums1[right] > itr->second) {
            res[itr->first] = nums1[right];
            right--;
        } else {
            res[itr->first] = nums1[left];
            left++;
        }
    }
    return res;
}