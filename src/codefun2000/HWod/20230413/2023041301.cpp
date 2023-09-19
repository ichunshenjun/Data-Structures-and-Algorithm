#include <cstdio>
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
int main() {
    string s;
    int n;
    cin >> n;
    int sz = 0;
    int res = 0;
    int order = 0;
    getchar();
    for (int i = 0; i < 2 * n; i++) {
        getline(cin, s);
        if (s[0] == 'h') {
            if (sz > 0) {
                order++;
            }
            sz++;
        } else if (s[0] == 't') {
            sz++;
        } else if (s[0] == 'r') {
            if (order > 0) {
                order = 0;
                res += 1;
            }
            sz--;
        }
    }
    cout << res;
    return 0;
}