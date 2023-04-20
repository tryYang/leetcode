#include<iostream>
#include<vector>
#include"bits/stdc++.h"
using namespace std;
string longestPalindrome(const string& s);
int main(){

    string test= "cbbd";
    cout<<longestPalindrome(test);


    return 0;
}
string longestPalindrome(const string& s){
    int n=s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }
    int start=0;
    int maxlen=0;
    for(int L=2;L<=n;L++){
        for(int i=0;i<n-L+1;i++){
            int j=i+L-1;
            if(j>=n)
                break;
            if(s[i]!=s[j]){
               
                dp[i][j]=false;
            }
            else{
                if(j-i<3){
                    dp[i][j]=true;
                }
                 else{
                    dp[i][j]=dp[i+1][j-1];
                 }
            }
            if(dp[i][j]&&j-i+1>maxlen)
                {
                    maxlen=j-i+1;
                    start=i;
                }
            
        }
    }
    return s.substr(start,maxlen);
}

// 给你一个字符串 s，找到 s 中最长的回文子串。
// s="babad"
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 