// 11
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height);
int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}
int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    while (left < right) {
        int max_area = min(height[left], height[right]) * (right - left);
        res = max(res, max_area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}