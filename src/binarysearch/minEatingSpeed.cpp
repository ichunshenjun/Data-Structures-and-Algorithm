// 875
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h);
bool check(vector<int>& piles, int mid, int h);
int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int res;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(piles, mid, h)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}
bool check(vector<int>& piles, int mid, int h) {
    long long time = 0;
    for (auto pile : piles) {
        if (pile % mid == 0) {
            time += pile / mid;
        } else {
            time += pile / mid + 1;
        }
    }
    if (time <= h) {
        return true;
    }
    return false;
}