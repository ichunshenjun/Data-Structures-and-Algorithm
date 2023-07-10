#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int shipWithinDays(vector<int>& weights, int days);
int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int res = shipWithinDays(weights, days);
    cout << res << endl;
    return 0;
}
int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int need = 0;
        int cnt = 1;
        for (auto weight : weights) {
            if (need + weight > mid) {
                need = 0;
                cnt++;
            }
            need += weight;
        }
        if (cnt < days) {
            right = mid - 1;
        } else if (cnt == days) {
            right = mid - 1;
        } else if (cnt > days) {
            left = mid + 1;
        }
    }
    return left;
}
