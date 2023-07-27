// 415
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
string addStrings(string num1, string num2);
int main() {
    string num1 = "456", num2 = "77";
    cout << addStrings(num1, num2) << endl;
    return 0;
}
string addStrings(string num1, string num2) {
    stack<string> sk;
    int i = num1.size() - 1, j = num2.size() - 1;
    int flag = 0;
    int num = 0;
    while (i >= 0 && j >= 0) {
        if (num1[i] - '0' + num2[j] - '0' + flag >= 10) {
            num = num1[i] - '0' + num2[j] - '0' - 10 + flag;
            flag = 1;
        } else {
            num = num1[i] - '0' + num2[j] - '0' + flag;
            flag = 0;
        }
        sk.push(to_string(num));
        i--;
        j--;
    }
    while (i >= 0) {
        if (num1[i] - '0' + flag >= 10) {
            num = num1[i] - '0' + flag - 10;
            flag = 1;
        } else {
            num = num1[i] - '0' + flag;
            flag = 0;
        }
        sk.push(to_string(num));
        i--;
    }
    while (j >= 0) {
        if (num2[j] - '0' + flag >= 10) {
            num = num2[j] - '0' + flag - 10;
            flag = 1;
        } else {
            num = num2[j] - '0' + flag;
            flag = 0;
        }
        sk.push(to_string(num));
        j--;
    }
    if (flag == 1) sk.push(to_string(1));
    string res = "";
    while (!sk.empty()) {
        res += sk.top();
        sk.pop();
    }
    return res;
}