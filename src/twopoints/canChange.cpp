// 2337
#include <iostream>
#include <vector>
using namespace std;
bool canChange(string start, string target);
int main() {
    string start = "R_L_";
    string target = "__LR";
    cout << canChange(start, target) << endl;
    return 0;
}
bool canChange(string start, string target) {
    int i = 0, j = 0;
    int m = start.size(), n = target.size();
    while (i < m && j < n) {
        while (start[i] == '_') i++;
        while (target[j] == '_') j++;
        if (start[i] == target[j]) {
            if (i < j && start[i] == 'L') {
                return false;
            }
            if (i > j && start[i] == 'R') {
                return false;
            }
            i++;
            j++;
        } else {
            return false;
        }
    }
    if (i < m) {
        while (start[i] == '_') i++;
    }
    if (j < n) {
        while (target[j] == '_') j++;
    }
    if (i < m || j < n) {
        return false;
    }
    return true;
}
