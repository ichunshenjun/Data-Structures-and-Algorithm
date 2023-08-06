// 792
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int numMatchingSubseq(string s, vector<string>& words);
int left_bound(vector<int>& arr, int target);
int main() {
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};
    cout << numMatchingSubseq(s, words);
    return 0;
}
int numMatchingSubseq(string s, vector<string>& words) {
    int m = s.size();
    int res = 0;
    unordered_map<char, vector<int>> index;
    for (int i = 0; i < m; i++) {
        index[s[i]].push_back(i);
    }
    for (auto word : words) {
        int i = 0, j = 0;
        int n = word.size();
        for (; i < n; i++) {
            if (index[word[i]].empty()) {
                break;
            }
            int pos = left_bound(index[word[i]], j);
            if (pos == -1) {
                break;
            }
            j = index[word[i]][pos] + 1;
        }
        if (i == n) {
            res++;
        }
    }
    return res;
}
int left_bound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left == (int)arr.size()) return -1;
    return left;
}