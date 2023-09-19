#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a[i] = a[i] * (n - i);
    sort(a.begin(), a.end());
    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum < m)
            res++;
        else {
            cout << res << endl;
            break;
        }
    }
    return 0;
}