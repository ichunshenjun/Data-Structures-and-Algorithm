#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures);
int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res = dailyTemperatures(temperatures);
    for (auto a : res) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    vector<int> res(temperatures.size());
    for (int i = (int)temperatures.size() - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }
        res[i] = st.empty() ? 0 : (st.top() - i);
        st.push(i);
    }
    return res;
}