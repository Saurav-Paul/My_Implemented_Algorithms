				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

using vec = vector<int> ;
const int nax = 1e5 + 10;

vec indegree(nax);
vec graph[nax] ;
vec dp(nax, -1 ) ;

int dfs(int node){
	if(dp[node] != -1 ) return dp[node];
	int cnt = 0;
	for(auto x : graph[node] ){
		cnt = max(dfs(x) , cnt );
	}
	return dp[node] = cnt + 1; 
}


int main()
{
	int vertex, edge ;
	scanf("%d%d",&vertex,&edge);
	
	for(int i = 0 ; i < edge ; i++){
		int a , b; 
		scanf("%d%d",&a,&b);
		graph[a].emplace_back(b);
		indegree[b] ++;
	}
	
	int ans = 0;
	for( int i = 1; i <= vertex ; i++){
		if(indegree[i] == 0 ){
			ans = max(ans,dfs(i) );
		}
		
	}
	
	printf("%d\n",ans-1);
    return 0;
}
