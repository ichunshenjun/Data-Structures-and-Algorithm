// 969
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> pancakeSort(vector<int>& arr);
int main() {
    vector<int> arr = {1, 2, 3};
    auto res = pancakeSort(arr);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
vector<int> pancakeSort(vector<int>& arr) {
    int n = arr.size();
    int j = n - 1;
    vector<int> res;
    while (j >= 0) {
        int maxn = 0, index = 0;
        for (int i = 0; i <= j; i++) {
            if (arr[i] > maxn) {
                maxn = arr[i];
                index = i;
            }
        }
        if (index == j) {
            j--;
            continue;
        }
        reverse(arr.begin(), arr.begin() + index + 1);
        res.push_back(index + 1);
        reverse(arr.begin(), arr.begin() + j + 1);
        res.push_back(j + 1);
        j--;
    }
    return res;
}