#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll> vec;
void max_self(ll &a, ll b){
a=max(a,b);
}
int main(){
ll n, w; scanf("%lld %lld",&n,&w);
vec dp(w+1);
for(int i=0; i<n ; i++){
ll weight, value; scanf("%lld %lld",&weight,&value);
for(int now_weight=w-weight ; now_weight>=0 ; --now_weight){
    max_self(dp[now_weight+weight],dp[now_weight]+value);
}
}
ll ans=0;
for(auto i: dp)
    max_self(ans,i);
printf("%lld\n",ans);
return 0;
}
 
