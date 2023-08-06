#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    vector<string> ss;
    vector<vector<int>> logs;
    for (int j = 0; j < n; j++) {
        cin >> s;
        int same = 0;
        int simli = 0;
        int seed = 133;
        int hs = 1e+7 + 6;
        string time;
        int i = 0;
        while (s[i] != ':') {
            time += s[i] - '0';
            i++;
        }
        int res = 0;
        for (int k = 0; k < (int)time.size(); k++) {
            res = res * 10 + time[k];
        }
        for (; i < (int)s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                simli = (simli * seed + s[i]) % hs;
            }
            same = (same * seed + s[i]) % hs;
        }
        ss.push_back(s);
        logs.push_back({res, same, simli});
    }
    vector<int> ans1;
    vector<int> ans2;
    for (int i = 0; i < (int)logs.size(); i++) {
        bool f = true;
        int cnt = 0;
        for (int j = ans1.size() - 1; j >= 0; j--) {
            if (logs[i][0] - logs[ans1[j]][0] < 10 && logs[i][1] == logs[ans1[j]][1]) {
                ans2.push_back(i);
                f = false;
                break;
            } else if (logs[i][0] - logs[ans1[j]][0] < 100 && logs[i][2] == logs[ans1[j]][2]) {
                if (cnt == 8) {
                    f = false;
                    ans2.push_back(i);
                    break;
                }
                cnt++;
            } else if (logs[i][0] - logs[ans1[j]][0] >= 100) {
                break;
            }
        }
        if (f) {
            ans1.push_back(i);
        }
    }
    for (int i : ans2) {
        cout << ss[i] << endl;
    }
    return 0;
}