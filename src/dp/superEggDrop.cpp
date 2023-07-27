// 887 注意这里如果memo用map的话是更慢的过不了测试
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// unordered_map<string, int>memo;
vector<vector<int>> memo;
int superEggDrop(int k, int n);
int dp(int K, int N);
int main() {
    int k = 3, n = 14;
    cout << superEggDrop(k, n) << endl;
    return 0;
}
int superEggDrop(int k, int n) {
    memo = vector<vector<int>>(k + 1, vector<int>(n + 1, -666));
    return dp(k, n);
}
int dp(int K, int N) {
    int res = INT32_MAX - 1;
    if (K == 1) return N;
    if (N == 0) return 0;
    // string key=to_string(K)+","+to_string(N);
    // if(memo.count(key)){
    //     return memo[key];
    // }
    if (memo[K][N] != -666) {
        return memo[K][N];
    }
    int left = 1, right = N;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int broken = dp(K - 1, mid - 1);
        int unbroken = dp(K, N - mid);
        if (broken > unbroken) {
            right = mid - 1;
            res = min(res, broken + 1);
        } else {
            left = mid + 1;
            res = min(res, unbroken + 1);
        }
    }
    // memo[key]=res;
    memo[K][N] = res;
    return res;
}