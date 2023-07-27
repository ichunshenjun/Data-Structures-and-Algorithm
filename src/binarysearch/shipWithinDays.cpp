// 1011
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int shipWithinDays(vector<int>& weights, int days);
bool check(vector<int>& weights, long long mid, int days);
int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(weights, days) << endl;
    return 0;
}
int shipWithinDays(vector<int>& weights, int days) {
    long long left = 1;
    long long right = INT64_MAX;
    long long res;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(weights, mid, days)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}
bool check(vector<int>& weights, long long mid, int days) {
    int sum = 0;
    int n = weights.size();
    int i = 0;
    int cnt = 0;
    while (i < n) {
        if (sum + weights[i] > mid) {
            if (sum == 0) {
                return false;
            }
            sum = 0;
            cnt++;
        } else {
            sum += weights[i];
            i++;
        }
    }
    if (cnt + 1 > days) {
        return false;
    } else {
        return true;
    }
}