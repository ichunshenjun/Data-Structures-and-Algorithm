// 115
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>>memo;
int numDistinct(string s, string t);
int dp(string s,int i,string t,int j);
int main(){
    string s = "babgbag", t = "bag";
    cout<<numDistinct(s,t)<<endl;
    return 0;
}
int numDistinct(string s, string t) {
    memo=vector<vector<int>>(s.length(),vector<int>(t.length(),-1));
    return dp(s,0,t,0);
}
int dp(string s,int i,string t,int j){
    int res=0;
    int m = s.length(), n = t.length();
    if(j==n){
        return 1;
    }
    if(n-j>m-i){
        return 0;
    }
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    if(s[i]==t[j]){
        res=res+dp(s,i+1,t,j+1)+dp(s,i+1,t,j);
    }
    else{
        res+=dp(s,i+1,t,j);
    }
    memo[i][j]=res;
    return res;
}