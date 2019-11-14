				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int nax = 1e3 + 5;
char s[nax][nax] ;

int main()
{
	int n , m;
	scanf("%d%d",&n,&m);
	for(int i  = 0 ; i < n; i++) scanf("%s",s[i]);
	
	vector< vector<int> > dp(n,vector<int>(m) ) ;
	dp[0][0] = 1;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '#') continue ;
			if(i) dp[i][j] = (dp[i-1][j]%mod + dp[i][j]%mod)%mod;
			if(j) dp[i][j] = (dp[i][j-1]%mod + dp[i][j]%mod)%mod;
		}
	}
	
	printf("%d\n",dp[n-1][m-1] );
    return 0;
}
