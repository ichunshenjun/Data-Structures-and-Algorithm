// 2569 线段树不会下面的代码超时
#include <iostream>
#include <vector>
using namespace std;
vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries);
int main() {
    vector<int> nums1 = {1, 0, 1};
    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> queries = {{1, 1, 1}, {2, 1, 0}, {3, 0, 0}};
    auto res = handleQuery(nums1, nums2, queries);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}
vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    vector<long long> res;
    for (auto query : queries) {
        if (query[0] == 1) {
            for (int i = query[1]; i <= query[2]; i++) {
                if (nums1[i] == 0) {
                    nums1[i] = 1;
                } else if (nums1[i] == 1) {
                    nums1[i] = 0;
                }
            }
        } else if (query[0] == 2) {
            for (int i = 0; i < (int)nums2.size(); i++) {
                nums2[i] = nums2[i] + nums1[i] * query[1];
            }
        } else if (query[0] == 3) {
            long long sum = 0;
            for (auto num : nums2) {
                sum += num;
            }
            res.push_back(sum);
        }
    }
    return res;
}