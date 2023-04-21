#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b);
int main(){

    int x,y;
    cin>>x>>y;
    if(x<y)
    {
        int temp=x;
        x=y;
        y=temp;
    }
    cout<<gcd(x,y)<<endl;
    return 0;
}
int gcd(int a,int b){

    return b==0?a:gcd(b,a%b);


}