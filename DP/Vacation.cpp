				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n ; scanf("%d",&n);
	vector<int> dp(3);
	
	for(int day = 0 ; day < n; day ++){
		vector<int> v(3) , newdp(3);
		for(auto &x : v ) scanf("%d",&x);
		
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				if(i != j)
					newdp[i] = max(newdp[i] , dp[j] + v[i] );
			}
		}
		dp = newdp;
	}
	printf("%d\n",max({dp[0],dp[1],dp[2]})) ;
    return 0;
}
