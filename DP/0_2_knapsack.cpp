				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int item, knapsack;
	scanf("%d%d",&item,&knapsack);
	
	const int nax = 1e3 * item + 90;
	const int INF = 1e9 + 90;
	vector<long long int > dp(nax,INF);
	dp[0] = 0;
	
	for(int i = 0 ; i < item ; i++){
		int w , v;
		scanf("%d%d",&w,&v);
		
		for(int value = nax-1 ; value >= v ; value--) {
			dp[value] = min( dp[value ] , dp[value-v] + w );
		}
	}
	
	long long int ans = 0;
	for(int x = nax-1 ; x >= 0 ; x--){
		if(dp[x] <= knapsack ){
			ans = x;
			break ;
		}
	}
	
	printf("%lld\n",ans);
	
    return 0;
}
