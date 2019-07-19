#include<bits/stdc++.h>
using namespace std;
const int nax = 1e4 + 10;
int dp[nax];

int Grundy(int n){
	if(n==2 || n==1)
		return 0;
	if(dp[n] != -1)
		return dp[n];
	int mid = n/2;
	if(n%2==0)	mid--;
	set<int> x;
	for(int i = 1; i <= mid ; i++)
		x.insert(Grundy(i)^Grundy(n-i));
	int g = 0;
	while(x.count(g))
		g++;
	
	return dp[n] = g;
}

void solve(int caseno){
	
	int n; scanf("%d",&n);
	long long int Xor = 0;
	for(int i =0 ; i < n; i++){
		int temp ; scanf("%d",&temp);
		Xor ^= Grundy(temp);
	}
	printf("Case %d: ",caseno);
	puts(Xor? "Alice" : "Bob");
	
	return ;
	
}

int main(){
	memset(dp , -1 , sizeof dp);
	int t, cn = 0;
	scanf("%d",&t);
	while(t--)
		solve(++cn);
		
	return 0;
}
