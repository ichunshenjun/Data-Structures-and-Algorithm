#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h);
int main() {
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    int res = minEatingSpeed(piles, h);
    cout << res << endl;
    return 0;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long need = 0;
        for (auto pile : piles) {
            need += pile / mid;
            if (pile % mid) {
                need++;
            }
        }
        if (need > h) {
            left = mid + 1;
        } else if (need < h) {
            right = mid - 1;
        } else if (need == h) {
            right = mid - 1;
        }
    }
    return left;
}