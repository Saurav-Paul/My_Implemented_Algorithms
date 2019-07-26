#include<bits/stdc++.h>
using namespace std;

class obj{
	public :
		int u ,v, cost;
	obj(int c ,int a , int b){
		v = a, cost = b;
		u = c;
	}
};

class Compare{
	public :
		bool operator () (obj &a , obj &b){
			return a.cost > b.cost ;
		}
};
void solve(int cn){
	
	int city , road;
	scanf("%d%d",&city,&road);
	vector<obj> graph[city+1];
	
	
	for(int i = 0 ; i < road ; i++){
		int u , v , w;
		scanf("%d%d%d",&u,&v,&w);
		obj temp(u,v,w);
		obj temp2(v,u,w);
		graph[u].emplace_back(temp);
		graph[v].emplace_back(temp2);
		
	}
	
	int home ;
	scanf("%d",&home);
	priority_queue <obj , vector<obj> , Compare > pq;
	printf("Case %d:\n",cn);
	bool taken[city+10] = {};
	
	vector< int > dist(city+10,-1);
	dist[home] = 0;
	taken[home] = true ;
	for(auto x : graph[home])
		pq.push(x);
		
	while(!pq.empty()){
		obj temp = pq.top();
		pq.pop();
		
		if(taken[temp.v])
			continue ;
		taken[temp.v] = true;
		dist[temp.v] = max(dist[temp.u],temp.cost);
		for(auto x : graph[temp.v]){
			pq.push(x);
		}
		
	}
	for(int i = 0 ; i < city ; i++){
		if(dist[i]==-1)
			puts("Impossible");
		else
			printf("%d\n",dist[i]);
	}
	
	return ;
}


int main(){
	int t , cn = 0;
	scanf("%d",&t);
	while(t--)
		solve(++cn);
		
	return 0;
}
