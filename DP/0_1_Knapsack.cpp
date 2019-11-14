				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int item , knapsack;
	scanf("%d%d",&item,&knapsack);
	
	vector<long long int> dp(knapsack+10);
	for(int i = 0 ; i < item; i++){
		int w , v; 
		scanf("%d%d",&w,&v);
		for(int weight = knapsack ; weight >= w ; weight--){
			if(weight-w == 0 or dp[weight-w] ){
				dp[weight] = max(dp[weight-w] + v , dp[weight] );
			}
		}
	}
	
	long long int mx = 0;
	for(auto x : dp) mx = max(mx,x);
	
	printf("%lld\n",mx);
	
    return 0;
}
