#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    long long n;
    vector<long long> sk;
    while (scanf("%lld", &n) != EOF) {
        while (1) {
            bool flag = false;
            if (!sk.empty() && n == sk.back()) {
                sk.pop_back();
                n = 2 * n;
                flag = true;
            }
            int top = sk.size();
            int sum = 0;
            for (int i = top - 1; i >= 0; i--) {
                sum += sk[i];
                if (sum == n) {
                    sk.erase(sk.begin() + i, sk.end());
                    n = 2 * n;
                    flag = true;
                    break;
                }
            }
            if (flag == false) break;
        }
        sk.push_back(n);
    }
    for (int i = sk.size() - 1; i >= 0; i--) {
        cout << sk[i] << " ";
    }
    return 0;
}