#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int maxp=INT32_MIN;
    int res;
    vector<vector<int>> profit(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>profit[i][j];
        }
    }
    vector<vector<int>>preSum(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]+profit[i-1][j-1]-preSum[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            preSum[i][j]-=i*j*5;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int s=i;s<=n;s++){
                for(int e=j;e<=m;e++){
                    int cnt=(s-i+1)*(e-j+1);
                    int money=preSum[s][e]-preSum[i-1][e]-preSum[s][j-1]+preSum[i-1][j-1];
                    if(money>maxp){
                        res=cnt;
                        maxp=money;
                    }
                    if(money==maxp){
                        res=min(res,cnt);
                    }
                }
            }
        }
    }
    cout<<res<<" "<<maxp<<endl;
    return 0;
}
