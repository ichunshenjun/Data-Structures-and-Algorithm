#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
using namespace std;
int findKthLargest(vector<int>& nums, int k);
int partition(vector<int>& nums, int left, int right);
void swap(vector<int>& nums, int i, int j);
int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    auto res = findKthLargest(nums, k);
    cout << res << endl;
    return res;
}
// int findKthLargest(vector<int>& nums, int k) {
//     auto cmp = [](int a, int b) { return a > b; };
//     std::priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
//     for (auto num : nums) {
//         pq.emplace(num);
//         if ((int)pq.size() > k) {
//             pq.pop();
//         }
//     }
//     return pq.top();
// }
//上面解法采用了小顶堆,时间复杂度为O(Nlogk),下面是用快速排序实现的版本时间复杂度更低只有O(n)
int findKthLargest(vector<int>& nums, int k) {
    std::random_device rd;
    std::mt19937 rng(rd());

    // 打乱数组顺序
    std::shuffle(nums.begin(), nums.end(), rng);
    int left = 0, right = nums.size() - 1;
    k = nums.size() - k;
    while (left <= right) {
        int p = partition(nums, left, right);
        if (p < k) {
            left = p + 1;
        } else if (p > k) {
            right = p - 1;
        } else {
            return nums[p];
        }
    }
    return -1;
}
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (i < right && nums[i] <= pivot) {
            i++;
        }
        while (j > left && nums[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(nums, i, j);
    }
    swap(nums, left, j);
    return j;
}
void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}