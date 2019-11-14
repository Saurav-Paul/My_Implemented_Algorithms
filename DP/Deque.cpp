						/*Saurav Paul*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

template<typename T> void ara_read(T &v,ll n){
	ll temp;
	for(ll i=0; i< n; i++){
		scanf("%lld",&temp);
		v.emplace_back(temp);
	}
}

int const nax = 3005;
ll dp[nax][nax] ;	

int main()
{
	
	int n;
	scanf("%d",&n);
	vector < int > in;
	ara_read(in,n);
	
	for(int L=n-1; L >=0 ; L--){
		
		for(int R = L ; R < n ; R++){
			if(L==R){
				dp[L][R] = in[L] ;
			}else{
				
				dp[L][R] = max(in[L] - dp[L+1][R] , in[R] - dp[L][R-1]);
			}
		}
	}
	
	printf("%lld\n",dp[0][n-1]);
	
    return 0;
}
