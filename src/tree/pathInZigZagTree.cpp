#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> pathInZigZagTree(int label);
int main() {
    int label = 14;
    auto res = pathInZigZagTree(label);
    for (auto num : res) {
        cout << num << endl;
    }
    return 0;
}
vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    int level = 1;
    int nodes = 1;
    while (nodes * 2 <= label) {
        level++;
        nodes *= 2;
    }
    if (level % 2 == 0) {
        label = (1 << (level - 1)) + (1 << level) - 1 - label;
    }
    while (level > 0) {
        if (level % 2 == 0) {
            res.emplace_back((1 << (level - 1)) + (1 << level) - 1 - label);
        } else {
            res.emplace_back(label);
        }
        level--;
        label >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}