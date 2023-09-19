#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<int> pos1, pos2;
    for (int i = 0; i < k; i++) {
        if (w[i] > k) pos1.push_back(i);
    }
    for (int i = k; i < n; i++) {
        if (w[i] >= 1 && w[i] <= k) pos2.push_back(i);
    }
    int m = pos2.size();
    long long res = 0;
    for (int i = 0; i < m; i++) {
        res += pos2[i] - pos1[i];
    }
    cout << res << endl;
    return 0;
}