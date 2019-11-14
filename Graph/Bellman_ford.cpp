#include<bits/stdc++.h>
using namespace std;
using pii = pair <int, int > ;
using vec = vector<pii > ;
using ll = long long int;
const int INF = 1e9 + 90;

void dfs(vector< vec > &graph, int node , bool ok[] , vector<int>&store){
	
	if(ok[node])
		return ;
	store.emplace_back(node);
	ok[node] = true;
	
	for(auto x : graph[node]){
		dfs(graph,x.first,ok,store);
	}
	
	
}

bool bellmanford(vector<vec > &graph,int n , vector<int> &store){
	bool flag = false;
	
	vector<ll> dist(n+10,INF);
	
	for(int i = 1 ; i < n ; i++){
		for(int j = 0; j < n ; j++){
			for(auto x : graph[j]){
				if(dist[x.first] > dist[j] + x.second){
					dist[x.first] = dist[j] + x.second ;
				}
				
			}
			
		}
	}
	
	bool isvisited[n+10]={};
	
	for(int j = 0 ; j < n ; j++){
		
		for(auto x : graph[j]){
			
			if(dist[x.first] > dist[j] + x.second){
				flag = true;
				dist[x.first] = dist[j] + x.second ;
				
				dfs(graph,x.first,isvisited,store);
				
			}
				
			
		}
		
	}
	
	
	
	return flag;
}

void solve(){
	int n, m;
	scanf("%d%d",&n,&m);
	
	vector<vector<pii >  > graph(n+10);
	for(int i = 0 ; i < m; i++){
		int u, v, cost;
		scanf("%d%d%d",&u,&v,&cost);
		graph[v].emplace_back(u,cost);
		
	}
	
	vector<int> store;
	
	if(bellmanford(graph,n,store)){
		
		sort(store.begin(),store.end());
		
		for(auto x : store)
			printf(" %d",x);
		puts("");
		
	}
	else
		puts(" impossible");
	
}

int main(){
	int t;
	scanf("%d",&t);
	
	for(int i = 1; i <= t ; i++){
		printf("Case %d:",i);
		solve();
	}
	
	return 0;
}
