#include <cstdint>
#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int area;
int m,n;
int res=INT32_MAX;
vector<vector<bool>> visited;
void dfs(int i,int j,int count);
bool isValid(int i,int j,int k);
void fill(int i,int j,int k,bool arg);
int main(){
    cin>>m>>n;
    area=m*n;
    visited=vector<vector<bool>>(m,vector<bool>(n,false));
    dfs(0,0,0);
    cout<<res;
    return 0;
}
// 骗分
// unordered_map<int,unordered_set<int>> memo;
// void dfs(int sum,int count);
// void dfs(int sum,int count){
//     if(sum>area){
//         return;
//     }
//     if(sum==area){
//         res=min(res,count);
//     }
//     if(memo[sum].count(count)){
//         return;
//     }
//     for(int i=1;i<=min(m,n);i++){
//         sum+=i*i;
//         count++;
//         dfs(sum,count);
//         sum-=i*i;
//         count--;
//     }
//     memo[sum].insert(count);
// }
void dfs(int i,int j,int count){
    if(count>res){
        return;
    }
    if(j>=n){
        dfs(i+1,0,count);
        return;
    }
    if(i>=m){
        res=count;
        return;
    }
    if(visited[i][j]){
        dfs(i,j+1,count);
        return;
    }
    for(int k=min(m-i,n-j);k>=1;k--){
        if(isValid(i,j,k)){
            fill(i,j,k,true);
            dfs(i,j+k,count+1);
            fill(i,j,k,false);
        }
    }
}
bool isValid(int i,int j,int k){
    for(int x=i;x<i+k;x++){
        for(int y=j;y<j+k;y++){
            if(visited[x][y])
                return false;
        }
    }
    return true;
}
void fill(int i,int j,int k,bool arg){
    for(int x=i;x<i+k;x++){
        for(int y=j;y<j+k;y++){
            visited[x][y]=arg;
        }
    }
}