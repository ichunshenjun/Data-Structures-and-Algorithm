#include <iostream>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s);
int main() {
    string s = "abcabccb";
    int res = lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}
int lengthOfLongestSubstring(string s) {
    std::unordered_map<char, int> window;
    int left = 0, right = 0, res = 0;
    while (right < static_cast<int>(s.size())) {
        char c = s[right];
        window[c]++;
        right++;
        while (left < right && window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }
        res = max(res, right - left);
    }
    return res;
}