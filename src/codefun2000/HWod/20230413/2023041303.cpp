#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    unordered_map<char, int> map;
    stack<char> st;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        map[s[i]]++;
    }
    unordered_map<char, int> count;
    for (int i = 0; i < len; i++) {
        if (count[s[i]] == 2) {
            map[s[i]]--;
        } else {
            while (!st.empty() && st.top() < s[i] && map[st.top()] > 2) {
                map[st.top()]--;
                if (count[st.top()] > 0) count[st.top()]--;
                st.pop();
            }
            st.push(s[i]);
            count[s[i]]++;
        }
    }
    vector<char> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    return 0;
}