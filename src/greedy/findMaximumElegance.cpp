#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
long long findMaximumElegance(vector<vector<int>>& items, int k);
int main() {
    vector<vector<int>> items = {{3, 4}, {8, 4}, {2, 2}, {1, 3}};
    int k = 2;
    cout << findMaximumElegance(items, k);
    return 0;
}
long long findMaximumElegance(vector<vector<int>>& items, int k) {
    long long res = 0, total_profit = 0;
    sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) { return a[0] > b[0]; });
    unordered_set<int> visited;
    stack<int> duplicate;
    for (int i = 0; i < (int)items.size(); i++) {
        int profit = items[i][0], category = items[i][1];
        if (i < k) {
            total_profit += profit;
            if (!visited.insert(category).second) {
                duplicate.push(profit);
            }
        } else if (!duplicate.empty() && visited.insert(category).second) {
            total_profit += profit - duplicate.top();
            duplicate.pop();
        }
        res = max(res, total_profit + (long long)visited.size() * (long long)visited.size());
    }
    return res;
}