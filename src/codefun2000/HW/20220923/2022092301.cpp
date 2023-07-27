#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
vector<int> postorder;
vector<int> order(vector<int>& nums);
int traverse(vector<vector<int>>& graph, int s);
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    auto res = order(nums);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i + 1 == n];
    }
    return 0;
}
vector<int> order(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        if (nums[i] != -1) graph[nums[i]].push_back(i);
    }
    postorder = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        postorder[i] = traverse(graph, i);
    }
    vector<int> indexes(n);
    iota(indexes.begin(), indexes.end(), 0);
    sort(indexes.begin(), indexes.end(), [&](int i, int j) {
        if (postorder[i] == postorder[j]) {
            return i < j;
        }
        return postorder[i] > postorder[j];
    });
    return indexes;
}
int traverse(vector<vector<int>>& graph, int s) {
    int res = 1;
    if (postorder[s]) return postorder[s];
    for (int t : graph[s]) {
        res += traverse(graph, t);
    }
    return res;
}
