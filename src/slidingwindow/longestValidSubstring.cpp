// 2781
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int longestValidSubstring(string word, vector<string>& forbidden);
int main() {
    string word = "acbc";
    vector<string> forbidden = {"cbc", "acb", "acbc"};
    cout << longestValidSubstring(word, forbidden) << endl;
    return 0;
}
int longestValidSubstring(string word, vector<string>& forbidden) {
    unordered_set<string> fb{forbidden.begin(), forbidden.end()};
    // int res=0,left=0,n=word.size();
    // for(int right=0;right<n;right++){
    //     for(int i=right;i>=left&&i>right-10;i--){
    //         if(fb.count(word.substr(i,right-i+1))){
    //             left=i+1;
    //             break;
    //         }
    //     }
    //     res=max(res,right-left+1);
    // }
    int res = 0, n = word.size();
    int right = n - 1;
    for (int left = n - 1; left >= 0; left--) {
        int rb = min(left + 9, right);
        for (int i = left; i <= rb; i++) {
            string str = word.substr(left, i - left + 1);
            if (fb.count(str)) {
                right = left + str.size() - 2;
                if (right == left) {
                    right--;
                }
                break;
            }
        }
        res = max(res, right - left + 1);
    }
    return res;
}