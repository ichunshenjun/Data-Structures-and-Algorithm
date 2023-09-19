#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
int f(int mask, int sum, int l, int r, int k);
int main() {
    int q;
    cin >> q;
    int l, r, k;
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
        cout << f(0, 0, l, r, k) << endl;
    }
    return 0;
}
int f(int mask, int sum, int l, int r, int k) {
    int res = 0;
    if (sum > r) {
        return 0;
    }
    for (int i = 0; sum + pow(k, i) <= r; i++) {
        if (mask & (1 << i)) {
            continue;
        }
        res += f(mask | (1 << i), sum + pow(k, i), l, r, k) + 1;
    }
    return res;
}