// 2208
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int halveArray(vector<int>& nums);
int main() {
    vector<int> nums = {5, 19, 8, 1};
    cout << halveArray(nums) << endl;
    return 0;
}
int halveArray(vector<int>& nums) {
    double sum = 0;
    priority_queue<double> pq;
    for (auto num : nums) {
        sum += num;
        pq.push(num);
    }
    double gap = 0;
    int res = 0;
    while (gap < sum / 2) {
        double top = pq.top();
        pq.pop();
        gap += top / 2;
        pq.push(top / 2);
        res++;
    }
    return res;
}