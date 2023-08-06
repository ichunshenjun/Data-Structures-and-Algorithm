#include <iostream>
#include <vector>
using namespace std;
long long stringtoLong(string& s);
bool isSame(long long num);
int main() {
    string M;
    long long N;
    char k;
    cin >> M >> N >> k;
    int m = M.size();
    string res;
    long long ans = 0;
    for (int i = 12; i >= 3; i--) {
        for (int j = 0; j < m - i + 1; j++) {
            string temp = M.substr(j, i);
            long long num = stringtoLong(temp);
            switch (k) {
                case '-':
                    if (isSame(num - N)) {
                        if (num - N > ans) {
                            res = temp;
                            ans = num - N;
                        }
                    }
                    break;
                case '+':
                    if (isSame(num + N)) {
                        if (num + N > ans) {
                            res = temp;
                            ans = num + N;
                        }
                    }
                    break;
                case '*':
                    if (isSame(num * N)) {
                        if (num * N > ans) {
                            res = temp;
                            ans = num * N;
                        }
                    }
                    break;
            }
        }
    }
    if (res.size() == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < (int)res.size(); i++) {
        if (res[i] == '0') {
            res = res.substr(i + 1, res.size() - i + 1);
        } else {
            break;
        }
    }
    cout << res;
    return 0;
}
long long stringtoLong(string& s) {
    int sz = s.size();
    long long res = 0;
    for (int i = 0; i < sz; i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}
bool isSame(long long num) {
    int a = num % 10;
    while (num) {
        if (num % 10 != a) return false;
        num /= 10;
    }
    return true;
}