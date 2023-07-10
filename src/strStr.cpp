#include <cstdint>
#include <iostream>
using namespace std;
int strStr(string haystack, string needle);
int main() {
    string haystack = "hello";
    string needle = "ll";
    auto res = strStr(haystack, needle);
    cout << res << endl;
    return 0;
}
int strStr(string haystack, string needle) {
    int L = needle.length();
    int R = 256;
    long Q = 1654325;
    long RL = 1;
    for (int i = 1; i <= L - 1; i++) {
        RL = (RL * R) % Q;
    }
    long patHash = 0;
    for (int i = 0; i < L; i++) {
        patHash = (R * patHash + needle[i]) % Q;
    }
    long windowHash = 0;
    int left = 0, right = 0;
    while (right < static_cast<int>(haystack.size())) {
        windowHash = ((R * windowHash) % Q + needle[right]) % Q;
        right++;
        if (right - left == L) {
            if (windowHash == patHash) {
                if (haystack.substr(left, right - left) == needle) {
                    return left;
                }
            }
            windowHash = (windowHash - (haystack[left] * RL) % Q + Q) % Q;
            left++;
        }
    }
    return -1;
}