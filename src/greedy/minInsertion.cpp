// 1541
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int minInsertions(string s);
int main() {
    string s = "(()))";
    cout << minInsertions(s) << endl;
    return 0;
}
int minInsertions(string s) {
    unordered_map<char, double> freq;
    unordered_map<char, double> need;
    for (int i = 0; i < (int)s.size(); i++) {
        freq[s[i]]++;
        switch (s[i]) {
            case '(':
                need[')'] += 2;
                break;
            case ')':
                if (need[')'] == 0) {
                    need['('] += 0.5;
                } else {
                    need[')']--;
                }
                break;
        }
    }
    if (need['('] != (int)need['(']) {
        double gap = need['('] - (int)need['('];
        return (int)need['('] + 1 + need[')'] + gap * 2;
    }
    return need['('] + need[')'];
}