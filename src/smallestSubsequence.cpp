#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
string smallestSubsequence(string s);
int main() {
    string s = "ecbacba";
    auto res = smallestSubsequence(s);
    cout << res << endl;
    return 0;
}
// 这种采用双指针的做法有问题比如eacb就找不出来
// string smallestSubsequence(string s){
//     unordered_map<char,int> need,window;
//     for(auto c:s){
//         need[c]=1;
//     }
//     int left=0,right=0;
//     int valid=0;
//     string res="";
//     while(right<static_cast<int>(s.size())){
//         char c=s[right];
//         right++;
//         if(need.count(c)){
//             window[c]++;
//             if(need[c]==window[c]){
//                 valid++;
//             }
//         }
//         while(valid==static_cast<int>(need.size())){
//             string str;
//             unordered_map<char,int> temp;
//             for(int i=left;i<right;i++){
//                 char c=s[i];
//                 if(need.count(c)){
//                     if(temp.count(c)==0){
//                         temp[c]=1;
//                         str+=c;
//                     }
//                 }
//             }
//             cout<<str<<endl;
//             if(res.size()==0){
//                 res=str;
//             }
//             res=res>str?str:res;
//             char d=s[left];
//             left++;
//             if(need.count(d)){
//                 if(need[d]==window[d]){
//                     valid--;
//                 }
//                 window[d]--;
//             }
//         }
//     }
//     return res;
// }
string smallestSubsequence(string s) {
    vector<int> visited(26);
    unordered_map<char, int> num;
    stack<char> stk;
    string res;
    for (char c : s) {
        num[c]++;
    }
    for (char c : s) {
        if (!visited[c - 'a']) {
            while (!stk.empty() && c < stk.top() && num[stk.top()]) {
                visited[stk.top() - 'a'] = 0;
                stk.pop();
            }
            stk.push(c);
            visited[c - 'a'] = 1;
        }
        num[c]--;
    }
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}