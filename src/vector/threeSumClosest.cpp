// 16
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int twoSumClosest(vector<int>& nums,int start,int target);
int threeSumClosest(vector<int>& nums, int target);
int main(){
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout<<threeSumClosest(nums, target)<<endl;
}
int threeSumClosest(vector<int>& nums, int target){
    if(nums.size()<3)
        return 0;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int delta=INT32_MAX;
    for(int i=0;i<n-2;i++){
        int sum=nums[i]+twoSumClosest(nums,i+1,target-nums[i]);
        if(abs(delta)>abs(target-sum))
            delta=target-sum;
    }
    return target-delta;
}
int twoSumClosest(vector<int>& nums,int start,int target){
    int left=start,right=nums.size()-1;
    int delta=INT32_MAX;
    while(left<right){
        int sum=nums[left]+nums[right];
        if(abs(target-sum)<abs(delta)){
            delta=target-sum;
        }
        if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return target-delta;
}