
#include<bits/stdc++.h>
using namespace std;
int cn = 0;

void solve(int n){
	
	map<string,int> code;
	vector<string> name(n+1);
	vector<int> indegree(n+1);
	vector<int> graph[n];
	for(int i = 0 ; i < n; i++){
		cin>>name[i];
		code[name[i]] = i;
		
	}
	
	int m; cin >> m;
	for(int i = 0 ; i < m ; i++){
		string s, t; cin >> s >> t;
		int a= code[s] , b = code[t];
		graph[a].emplace_back(b);
		indegree[b] ++;
		
	}

	vector<int> order;
	

	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 0 ; i < n; i++){
			if(indegree[i]==0){
				flag = true;
				indegree[i]=-1;
				order.emplace_back(i);
				for(int x : graph[i]){
					indegree[x]--;
				}
				break ;
			}
		}
	}
	
	cout <<"Case #"<<++cn<<": Dilbert should drink beverages in this order: ";
	
	int sz = (int)order.size();
	for(int i = 0 ; i < sz ; i++){
		cout << name[order[i]];
		if(i==sz-1)
			cout<<".\n";
		else
			cout<<" ";
	}
	cout <<"\n";
}

int main(){
	
	ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n)
		solve(n);
	
	return 0;
}
