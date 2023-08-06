// 241
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, vector<int>> memo;
vector<int> diffWaysToCompute(string expression);
int main() {
    string expression = "2*3-4*5";
    auto res = diffWaysToCompute(expression);
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " \n"[i + 1 == (int)res.size()];
    }
    return 0;
}
vector<int> diffWaysToCompute(string expression) {
    if (memo.count(expression)) {
        return memo[expression];
    }
    vector<int> res;
    /*************分************/
    for (int i = 0; i < (int)expression.length(); i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            /*************治************/
            for (int a : left) {
                for (int b : right) {
                    if (c == '+') {
                        res.push_back(a + b);
                    } else if (c == '-') {
                        res.push_back(a - b);
                    } else if (c == '*') {
                        res.push_back(a * b);
                    }
                }
            }
        }
    }
    if (res.empty()) {
        res.push_back(stoi(expression));
    }
    memo[expression] = res;
    return res;
}