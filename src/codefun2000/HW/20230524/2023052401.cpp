#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x;
    vector<int> mem;
    while (scanf("%d,", &x) != EOF) {
        mem.push_back(x);
    }
    sort(mem.begin(), mem.end());
    int len = 1, start = mem[0];
    int i = 0, j = 1;
    int m = mem.size();
    int tempLen = 1, tempStart = mem[0];
    while (i < m && j < m) {
        if (mem[j] == mem[j - 1] + 1) {
            tempLen++;
        } else {
            if (tempLen > len) {
                len = tempLen;
                start = tempStart;
            }
            tempLen = 1;
            tempStart = mem[j];
        }
        j++;
    }
    if (tempLen > len) {
        cout << tempStart << "," << tempLen;
        return 0;
    }
    cout << start << "," << len;
    return 0;
}