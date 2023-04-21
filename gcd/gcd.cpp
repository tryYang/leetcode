
// 默认 a比b大
int gcd(int a,int b){

    return b==0?a:gcd(b,b%a);


}