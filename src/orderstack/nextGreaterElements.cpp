#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums);
int main() {
    vector<int> nums = {1, 2, 3, 4, 3};
    auto res = nextGreaterElements(nums);
    for (auto vec : res) {
        cout << vec << " ";
    }
    cout << endl;
    return 0;
}
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    vector<int> res(nums.size());
    int size = nums.size();
    nums.insert(nums.end(), nums.begin(), nums.end());
    for (int i = 2 * size - 1; i >= size - 1; i--) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        s.push(nums[i]);
    }
    for (int i = size - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return res;
}