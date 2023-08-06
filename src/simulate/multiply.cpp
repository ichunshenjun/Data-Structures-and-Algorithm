// 43
#include <iostream>
#include <vector>
using namespace std;
string multiply(string num1, string num2);
int main() {
    string num1 = "123", num2 = "456";
    cout << multiply(num1, num2) << endl;
    return 0;
}
string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    int i = 0;
    while (i < (int)res.size() && res[i] == 0) i++;
    string str;
    for (; i < (int)res.size(); i++) str.push_back('0' + res[i]);
    return str.size() == 0 ? "0" : str;
}