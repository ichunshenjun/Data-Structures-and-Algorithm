// 1094
#include <iostream>
#include <vector>
using namespace std;
bool carPooling(vector<vector<int>>& trips, int capacity);
int main() {
    vector<vector<int>> trips = {{9, 0, 1}, {3, 3, 7}};
    int capacity = 4;
    cout << carPooling(trips, capacity) << endl;
    return 0;
}
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001, 0);
    for (auto trip : trips) {
        diff[trip[1]] += trip[0];
        diff[trip[2]] -= trip[0];
    }
    vector<int> res(1001, 0);
    res[0] = diff[0];
    for (int i = 1; i < (int)diff.size(); i++) {
        res[i] = res[i - 1] + diff[i];
    }
    for (int i = 0; i < (int)res.size(); i++) {
        if (res[i] > capacity) {
            return false;
        }
    }
    return true;
}