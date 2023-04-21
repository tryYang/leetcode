#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

// 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

// 0 <= j <= nums[i] 
// i + j < n
// 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。


int jump(vector<int>&nums);
int main(){
    vector<int> nums={2,3,1,1,4};
    cout<<jump(nums)<<endl;




    return 0;
}
int jump(vector<int>&nums){
    vector<int>dp(nums.size(),INT_MAX);
    int n =nums.size();
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j =0;j<i;j++){
            if(j+nums[j]>=i)
            dp[i]=min(dp[i],dp[j]+1);
        }
    } 
    return dp[n-1];
}