#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries);
int main() {
    int n = 6;
    vector<vector<int>> edges = {{5, 2}, {3, 5}, {4, 5}, {1, 5}, {1, 4}, {3, 5}, {2, 6}, {6, 4}, {5, 6}, {4, 6},
                                 {6, 2}, {2, 6}, {5, 4}, {6, 1}, {6, 1}, {2, 5}, {1, 3}, {1, 3}, {4, 5}};
    vector<int> queries = {6, 9, 2, 1, 2, 3, 6, 6, 6, 5, 9, 7, 0, 4, 5, 9, 1, 18, 8, 9};
    auto res = countPairs(n, edges, queries);
    for (int num : res) cout << num << " ";
    cout << endl;
    return 0;
}
vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
    vector<int> degree(n, 0);
    unordered_map<int, int> cnt;
    for (auto edge : edges) {
        int x = edge[0] - 1;
        int y = edge[1] - 1;
        if (x > y) swap(x, y);
        degree[x]++;
        degree[y]++;

        cnt[x * n + y]++;
    }
    vector<int> arr = degree;
    vector<int> res;
    sort(arr.begin(), arr.end());
    for (auto query : queries) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            int j = upper_bound(arr.begin() + i + 1, arr.end(), query - arr[i]) - arr.begin();
            total += n - j;
        }
        // for (int i = 0, j = n - 1; i < n; i++) {
        //         while (j > i && arr[i] + arr[j] > query) {
        //             j--;
        //         }
        //         total += n - 1 - max(i, j);
        // }
        for (auto& [val, freq] : cnt) {
            int x = val / n;
            int y = val % n;
            if (degree[x] + degree[y] > query && degree[x] + degree[y] - freq <= query) {
                total--;
            }
        }
        res.push_back(total);
    }
    return res;
}