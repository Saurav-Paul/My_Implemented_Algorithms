#include<bits/stdc++.h>
using namespace std;
bool flag = true ;

class node {
	public :
		bool endmark;
		node *next[10];
	
	node(){
		endmark = false;
		for(int i = 0 ; i < 10; i++)
			next[i] = NULL;
	}
	
} *root;

void insert(string &s){
	
	int sz = (int)s.size();
	node *curr = root;
	for(int i = 0; i < sz ;i++){
		int id = (int) s[i]-'0';
		if(curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
	if(curr->endmark && i==sz-1)
		flag=true;
	curr->endmark = true;
	}
	
	
}

void solve(){
	flag = false;
	root = new node();
	int n; cin >> n;
	vector<string>v(n);
	for(string &x : v)
		cin >> x;
	sort(v.rbegin(),v.rend());
	
	for(int i = 0 ; i < n; i++){
		insert(v[i]);
	}
	cout << (!flag? "YES":"NO") << endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	while(n--)
		solve();
		
	return 0;
}
