#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int num1,num2,gcd_ans;
    cin>>num1>>num2;
    gcd_ans=gcd(num1,num2);
    cout<<gcd_ans<<endl;
    return 0;
}
