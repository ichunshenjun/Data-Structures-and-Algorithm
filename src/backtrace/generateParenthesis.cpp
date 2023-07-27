// 22
#include <iostream>
#include <vector>
using namespace std;
vector<string> res;
vector<string> generateParenthesis(int n);
void backtrace(int n, int left, int right, string& s);
int main() {
    auto res = generateParenthesis(3);
    for (auto str : res) {
        cout << str << endl;
    }
    return 0;
}
vector<string> generateParenthesis(int n) {
    string s = "";
    backtrace(n, 0, 0, s);
    return res;
}
void backtrace(int n, int left, int right, string& s) {
    if (left == n && right == n) {
        res.push_back(s);
        return;
    }
    if (right > left || left > n || right > n) {
        return;
    }
    left = left + 1;
    s.push_back('(');
    backtrace(n, left, right, s);
    s.pop_back();
    left = left - 1;
    right = right + 1;
    s.push_back(')');
    backtrace(n, left, right, s);
    s.pop_back();
    right = right - 1;
}