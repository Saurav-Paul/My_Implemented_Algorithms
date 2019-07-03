#include<bits/stdc++.h>
using namespace std;

void test_case(int caseno){
	int n, q;
	scanf("%d%d",&n,&q);
	vector <int > tree(n*2);
	for(int i= 0; i < n ; i++){
		scanf("%d",&tree[n+i]);
	}
	// building segment tree...
	for(int i = n-1 ; i > 0 ;i--){
		tree[i]= min(tree[i<<1],tree[i<<1|1]);
	}
	// querying...
	printf("Case %d:\n",caseno);
	while(q--){
		int l, r;
		scanf("%d%d",&l,&r);
		l += n-1;
		r += n;
		int mini = 1e9 + 90;
		while(l < r){
			if(l&1)
				mini = min(mini,tree[l++]);
			
			if(r&1)
				mini = min(mini,tree[--r]);
	
			l>>=1;
			r>>=1;
		}
		printf("%d\n",mini);
	}
	
	return ;
}


int main(){
	
	int n;
	scanf("%d",&n);
	int caseno=0;
	while(n--)
		test_case(++caseno);
	return 0;
}
