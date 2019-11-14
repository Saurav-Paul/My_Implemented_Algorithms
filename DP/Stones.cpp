				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n , k ;
	scanf("%d%d",&n,&k);
	
	vector<int> v(n);
	for(int& x: v){
		scanf("%d",&x);
	}
	bool dp[k+1];
	memset(dp,0,sizeof dp);

	for(int i = 1 ; i <= k ; i++){
		for(int x : v){
			if(i >= x and !dp[i-x] ){
				dp[i] = true ;
			}
		}
	}
	
	puts(dp[k]?"First":"Second");
    return 0;
}
