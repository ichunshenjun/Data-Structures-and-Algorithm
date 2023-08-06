#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<pair<long long, long long>>& vecs, long long mid, int M);
int main() {
    int M, n;
    cin >> M >> n;
    long long x, y;
    vector<pair<long long, long long>> vecs;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vecs.push_back({x, y});
    }
    long long left = 1, right = INT64_MAX;
    long long ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(vecs, mid, M)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
//骗分的
bool check(vector<pair<long long, long long>>& vecs, long long mid, int M) {
    vector<pair<long long, long long>> sectionx;
    vector<pair<long long, long long>> sectiony;
    for (auto vec : vecs) {
        sectionx.push_back({vec.first - mid, vec.first + mid});
        sectiony.push_back({vec.second - mid, vec.second + mid});
    }
    vector<long long> begins, ends;
    for (auto section : sectionx) {
        begins.push_back(section.first);
        ends.push_back(section.second);
    }
    sort(begins.begin(), begins.end());
    sort(ends.begin(), ends.end());
    int countx = 0, county = 0;
    int res = 0;
    int szx = sectionx.size(), szy = sectiony.size();
    int i = 0, j = 0;
    while (i < szx && j < szx) {
        if (begins[i] <= ends[j]) {
            countx++;
            i++;
        } else {
            countx--;
            j++;
        }
        res = max(res, countx);
    }
    if (res < M) {
        return false;
    }
    begins.clear();
    ends.clear();
    for (auto section : sectiony) {
        begins.push_back(section.first);
        ends.push_back(section.second);
    }
    sort(begins.begin(), begins.end());
    sort(ends.begin(), ends.end());
    i = 0, j = 0, res = 0;
    while (i < szy && j < szy) {
        if (begins[i] <= ends[j]) {
            county++;
            i++;
        } else {
            county--;
            j++;
        }
        res = max(res, county);
    }
    if (res >= M) {
        return true;
    }
    return false;
}