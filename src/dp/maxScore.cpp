// 2786
#include <iostream>
#include <vector>
using namespace std;
vector<long long> memo;
long long maxScore(vector<int>& nums, int x);
long long dp(vector<int> &nums,int x,int i);
int main(){
    vector<int> nums = {1,8,4};
    int x = 7;
    cout<<maxScore(nums,x)<<endl;
    return 0;
}
// 这种解法超时了，要分为奇数的dp和偶数的dp
// long long maxScore(vector<int>& nums, int x){
//     int n=nums.size();
//     long long res=nums[0];
//     memo=vector<long long>(n,-1);
//     for(int i=1;i<n;i++){
//         res=max(res,dp(nums,x,i));
//     }
//     return res;
// }
// long long dp(vector<int> &nums,int x,int i){
//     if(memo[i]!=-1){
//         return memo[i];
//     }
//     int delta=(nums[i]%2+nums[0]%2)==1?-x:0;
//     long long res=nums[0]+nums[i]+delta;
//     for(int j=1;j<i;j++){
//         if(nums[i]%2+nums[j]%2==1){
//             res=max(res,dp(nums,x,j)+nums[i]-x);
//         }
//         else{
//             res=max(res,dp(nums,x,j)+nums[i]);
//         }
//     }
//     memo[i]=res;
//     return res;
// }
long long maxScore(vector<int>& nums, int x){
    int n=nums.size();
    vector<long long> dp(n,0);
    dp[0]=nums[0];
    long long res=nums[0];
    long long odd=-9999999,even=-9999999;
    if(nums[0]%2){
        odd=nums[0];
    }
    else{
        even=nums[0];
    }
    for(int i=1;i<n;i++){
        if(nums[i]%2){
            dp[i]=max(even-x,odd)+nums[i];
            odd=max(odd,dp[i]);
        }
        else{
            dp[i]=max(even,odd-x)+nums[i];
            even=max(even,dp[i]);
        }
        res=max(res,dp[i]);
    }
    return res;
}