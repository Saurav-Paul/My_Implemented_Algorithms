#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int> ;
const int INF = 1e9 + 90;

void solve(int cn){
	int n , m;
	scanf("%d%d",&n,&m);
	vector<pii> graph[n+1];
	
	for(int i = 0 ; i < m ; i++){
		int u , v, cost;
		scanf("%d%d%d",&u,&v,&cost);
		graph[u].emplace_back(cost,v);
		graph[v].emplace_back(cost,u);
	}
	
	vector<int> dist(n+1,INF);
	dist[1]=0;
	bool reached = false;
	priority_queue<pii> pq;
	pq.push({0,1});
	
	while(!pq.empty()){
		pii x = pq.top();
		pq.pop();
		
		if(x.second == n){
			reached = true;
		}
		
		for(auto y : graph[x.second]){
			if(dist[y.second] > dist[x.second] + y.first){
				dist[y.second] = dist[x.second] + y.first ;
				pq.push(y);
			}
		}
		
	}
	
	printf("Case %d: ",cn);
	if(reached){
		printf("%d\n",dist[n]);
	}
	else
		puts("Impossible");
	
	
}

int main(){
	
	int t , cn = 0;
	scanf("%d",&t);
	while(t--)
		solve(++cn);
	
	return 0;
}
