// 986
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList);
int main() {
    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
                        secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    intervalIntersection(firstList, secondList);
    return 0;
}
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    sort(firstList.begin(), firstList.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    sort(secondList.begin(), secondList.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    vector<vector<int>> res;
    int i = 0, j = 0;
    int m = firstList.size(), n = secondList.size();
    while (i < m && j < n) {
        if (firstList[i][1] < secondList[j][0]) {
            i++;
            continue;
        }
        if (secondList[j][1] < firstList[i][0]) {
            j++;
            continue;
        }
        res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
        if (firstList[i][1] <= secondList[j][1])
            i++;
        else
            j++;
    }
    return res;
}