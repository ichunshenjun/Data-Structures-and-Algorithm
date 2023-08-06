#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    vector<int> addrs;
    cin>>N;
    int addr;
    for(int i=0;i<N;i++){
        cin>>addr;
        addrs.push_back(addr);
    }
    int sz=addrs.size();
    int minn=INT32_MAX;
    int ans;
    sort(addrs.begin(),addrs.end());
    for(int i=0;i<sz;i++){
        int res=0;
        for(int j=0;j<sz;j++){
            res+=abs(addrs[i]-addrs[j]);
        }
        if(res<minn){
            minn=res;
            ans=addrs[i];
        }
    }
    cout<<ans;
    return 0;
}