// 1024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int videoStitching(vector<vector<int>>& clips, int time);
int main() {
    vector<vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
    int time = 10;
    cout << videoStitching(clips, time) << endl;
    return 0;
}
int videoStitching(vector<vector<int>>& clips, int time) {
    sort(clips.begin(), clips.end(), [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int curEnd = 0, nextEnd = 0;
    int cnt = 0, i = 0, n = clips.size();
    while (i < n && clips[i][0] <= curEnd) {
        while (i < n && clips[i][0] <= curEnd) {
            nextEnd = max(nextEnd, clips[i][1]);
            i++;
        }
        cnt++;
        curEnd = nextEnd;
        if (curEnd >= time) {
            return cnt;
        }
    }
    return -1;
}