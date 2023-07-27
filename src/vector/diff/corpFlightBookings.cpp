// 1109
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n);
int main() {
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;
    auto res = corpFlightBookings(bookings, n);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(20002, 0);
    for (auto booking : bookings) {
        diff[booking[0]] += booking[2];
        diff[booking[1] + 1] -= booking[2];
    }
    vector<int> res(20002, 0);
    res[0] = diff[0];
    for (int i = 1; i <= 20001; i++) res[i] = res[i - 1] + diff[i];
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        ans.push_back(res[i]);
    }
    return ans;
}