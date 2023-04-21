#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>&nums);
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组 是数组中的一个连续部分。

 
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};


    cout<<maxSubArray(nums)<<endl;
    return 0;
}
// 设定给dp[i] 是以i结尾的的最大子数组和
//  dp[i+1]   如果dp[i]>=0  dp[i+1]=dp[i]+nums[i+1]  else dp[i+1]=nums[i+1]
int maxSubArray(vector<int>&nums){
    int n=nums.size();
    vector<int> dp(n,INT_MIN);
    dp[0]=nums[0];
    if(n==1)
        return dp[0];
    int max=dp[0];
    for(int i=1;i<n;i++){
        if(dp[i-1]>=0)
            dp[i]=dp[i-1]+nums[i];
        else 
            dp[i]=nums[i];

        if(dp[i]>max)
            max=dp[i];
    }
    return max;

}