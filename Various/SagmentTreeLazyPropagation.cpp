#include<bits/stdc++.h>
using namespace std;

class obj{
	public :
		int value , prop ;
	
	obj(){
		value = 0;
		prop = 0;
	}
};

void update_tree(vector<obj> &tree, int l , int r, int st , int sp , int node){
	
	if(st > r or sp < l)
		return ;
	
	if(st >= l and sp <= r){
		tree[node].prop ++;
		return ;
	}
	int mid = st + ( (sp-st) >> 1);
	int lft = node << 1;
	int rght = lft + 1;
	
	update_tree(tree,l,r,st,mid,lft);
	update_tree(tree,l,r,mid+1,sp,rght);
	
}

int query(vector<obj> &tree, int l, int r , int st, int sp , int node){
	
	if(st > r or sp < l)
		return 0;
		
	if(st >= l and sp <=r){
		return tree[node].prop;
	}
	int mid = st + ( (sp-st) >> 1);
	int lft = node << 1;
	int rght = lft + 1;
	
	int s1 = query(tree,l,r,st,mid,lft);
	int s2 = query(tree,l,r,mid+1,sp,rght);
	return s1 + s2 + tree[node].prop;
}

bool check(vector<int> &x, vector<int> &y){
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int n = (int)x.size();
	for(int i = 0 ; i < n ; i++){
		if(x[i]!=y[i])
			return false;
	}
	
	return true;
}

void solve(){
	int n;
	scanf("%d",&n);
	vector<int> C(n),H(n),Level(n);
	
	for(auto &x : C)
		scanf("%d",&x);
	
	vector<obj> tree(4*n);
	
	for(auto &x : H)
		scanf("%d",&x);
		
	for(int i = 0 ; i < n ; i++){
		int x = C[i];
		int l = max(0,i-x) , r = min(n-1,i+x);
		update_tree(tree,l,r,0,n-1,1);
	}
	
	for(int i = 0 ; i < n ; i++){
		Level[i] = query(tree,i,i,0,n-1,1);
	}

	puts(check(H,Level)?"YES":"NO");
	
	
}

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
		
	return 0;
}
