				/*Saurav Paul*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

using vec = vector<int> ;

class obj{
	public :
		int u , v, cost ;
	obj(int a, int b, int c){
		u = a, v = b , cost = c;
	}
};

class Compare{
	public :
		bool operator ()(obj &a , obj & b){
			return a.cost > b.cost;
		}
};

int find_parent(int x, vec &parent){
	if(x==parent[x])
		return x;
		
	return parent[x] = find_parent(parent[x],parent);
}

void solve(int cn){
	
	int city, road, airport;
	scanf("%d%d%d",&city,&road,&airport);
	priority_queue< obj , vector<obj > , Compare > pq;
	
	vec parent(city+5);
	for(int i = 1 ; i <= city ; i ++)
		parent[i] = i;
		
	for(int i = 0 ; i < road ; i++){
		int u , v , cost;
		scanf("%d%d%d",&u,&v,&cost);
		obj x(u,v,cost);
		pq.push(x);
	}
	
	long long int sum = 0;
	
	while(!pq.empty()){
		
		obj x = pq.top();
		pq.pop();
		
		if(x.cost >= airport)
			break ;
		
		int a = find_parent(x.u,parent);
		int b = find_parent(x.v,parent);
		
		if(a != b){
			sum += x.cost;
			parent[a] = b;
		}
		
	}
	set <int > myset;
	for(int i = 1; i <= city ; i++)
		myset.insert(find_parent(i,parent));
	
	int need = (int)myset.size();
	
	printf("Case #%d: %lld %d\n",cn,(long long int)(airport*need+sum),need);
	
}

int main()
{
	int testcase,cn=0;
	scanf("%d",&testcase);
	while(testcase--)
		solve(++cn);
	
    return 0;
}
