// 2594
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long repairCars(vector<int>& ranks, int cars);
bool check(vector<int>& ranks, int cars, int mid);
int main() {
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;
    cout << repairCars(ranks, cars) << endl;
    return 0;
}
long long repairCars(vector<int>& ranks, int cars) {
    sort(ranks.begin(), ranks.end());
    long long left = 0, right = ranks[0] * cars * cars;
    long long res = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(ranks, cars, mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}
bool check(vector<int>& ranks, int cars, int mid) {
    for (auto rank : ranks) {
        cars -= (int)sqrt(mid / rank);
        if (cars <= 0) {
            return true;
        }
    }
    return false;
}