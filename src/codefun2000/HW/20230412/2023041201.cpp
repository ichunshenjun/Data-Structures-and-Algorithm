#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int value(vector<int>& nums, int bound);
bool check(vector<int>& nums, int mid, int bound);
int main() {
    vector<int> nums;
    int num, bound;
    string input;
    getline(cin, input);
    stringstream ss(input);
    while (ss >> num) {
        nums.push_back(num);
    }
    cin >> bound;
    cout << value(nums, bound) << endl;
    return 0;
}
int value(vector<int>& nums, int bound) {
    int n = nums.size();
    int maxn = 0;
    long long sum = 0;
    for (auto num : nums) {
        maxn = max(maxn, num);
        sum += num;
    }
    if (sum <= bound) {
        return -1;
    }
    int avg = bound / n;
    int left = avg, right = maxn;
    int res;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(nums, mid, bound)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}
bool check(vector<int>& nums, int mid, int bound) {
    long long sum = 0;
    for (auto num : nums) {
        num = num <= mid ? num : mid;
        sum += num;
        if (sum > bound) {
            return false;
        }
    }
    return true;
}