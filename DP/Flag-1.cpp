				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d",&n);
	vector<int> v(n);
	for(int i = 0 ; i < n; i++) scanf("%d",&v[i]);
	
	const int nax = 1e9 + 90;
	vector<int> dp(n,nax);
	dp[0] = 0;
	
	for(int i = 0 ; i < n; i++){
		for(int x : {i+1,i+2} ){
			if(x < n )
			dp[x] = min( abs(v[i]-v[x]) + dp[i] , dp[x] );
		}
	}
	printf("%d\n",dp[n-1]);
	return 0;
}
