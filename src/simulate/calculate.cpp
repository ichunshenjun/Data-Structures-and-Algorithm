// 224
#include <cctype>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int calculate(string s);
int helper(string& s, int& i);
int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(s) << endl;
    return 0;
}
int calculate(string s) {
    int i = 0;
    return helper(s, i);
}
int helper(string& s, int& i) {
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for (; i < (int)s.size(); i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (s[i] == '(') {
            i++;
            num = helper(s, i);
        }
        if ((!isdigit(s[i]) && s[i] != ' ') || i == (int)s.size() - 1) {
            switch (sign) {
                int pre;
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * num);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / num);
                    break;
            }
            sign = s[i];
            num = 0;
        }
        if (s[i] == ')') {
            i++;
            break;
        }
    }
    int res = 0;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    return res;
}
bool isdigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}