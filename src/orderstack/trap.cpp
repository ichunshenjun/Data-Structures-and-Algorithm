// 42
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int trap(vector<int>& height);
int main() {
    vector<int> height = {4, 2, 3};
    cout << trap(height) << endl;
    return 0;
}
int trap(vector<int>& height) {
    int n = height.size();
    stack<int> sk;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (!sk.empty() && height[i] > height[sk.top()]) {
            int top = sk.top();
            sk.pop();
            if (sk.empty()) {
                break;
            }
            int left = sk.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[i], height[left]) - height[top];
            res += currWidth * currHeight;
        }
        sk.push(i);
    }
    return res;
}