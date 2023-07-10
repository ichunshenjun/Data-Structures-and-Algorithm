#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maxEnvelopes(vector<vector<int>>& envelopes);
int main(){
    vector<vector<int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1},{1,1}};
    int res=maxEnvelopes(envelopes);
    cout<<res<<endl;
    return 0;
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n=envelopes.size();
    sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b){
        if(a[0]<b[0])
            return true;
        if(a[0]==b[0]&&a[1]>b[1])
            return true;
        return false;});
    vector<int> height(n);
    for(int i=0;i<n;i++){
        height[i]=envelopes[i][1];
    }
    int piles=0;
    vector<int> top(height.size(),0);
    for(int i=0;i<(int)height.size();i++){
        int poker=height[i];
        auto itr=lower_bound(top.begin(),top.begin()+piles,poker);
        if(itr==top.begin()+piles){
            piles++;
            top[piles-1]=poker;
        }
        else{
            top[itr-top.begin()]=poker;
        }

    }
    return piles;
}