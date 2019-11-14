						/*Saurav Paul*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

template<typename T> void max_self(T &a, T b){
	a=max(a,b);
}

const ll INF = 2e18 + 99;
typedef pair<ll,ll> Pair;
typedef vector<ll> vec;;

template<typename T> void ara_read(T &v,ll n){
	ll temp;
	for(ll i=0; i< n; i++){
		scanf("%lld",&temp);
		v.emplace_back(temp);
	}
}

ll query(int node,int a , int  b , int st , int sp ,vec &tree){
	
	assert(node);
	if(st > b || sp < a)
		return 0;
	if(st >=a && sp <=b)
		return tree[node];
		
	int lft = 2*node;
	int rght = 2*node + 1;
	int mid = (st+sp)/2;
	ll ans1 = query(lft,a,b,st,mid,tree);
	ll ans2 = query(rght,a,b,mid+1,sp,tree);
	
	return max(ans1,ans2);
}

void update_tree(int node ,int index ,int st , int sp ,ll newValue,vec &tree){
	if(sp < index || st > index)
		return ;
	if(st==sp){
		tree[node] = newValue;
		return ;
	}
	
	int lft = 2*node;
	int rght = 2*node +1 ;
	int mid= (st+sp)/2;
	update_tree(lft,index,st,mid,newValue,tree);
	update_tree(rght,index,mid+1,sp ,newValue,tree);
	
	tree[node] = max(tree[lft],tree[rght]);
	
}

int main()
{
	int n;
	scanf("%d",&n);
	vector <int > heights, beauties;
	ara_read(heights,n);
	ara_read(beauties,n);
	// segment tree.....
	
	vector <ll > tree(3*n);
	
	vector < ll > dp(n+1);
	for(int flower = 0 ; flower <n ; flower ++){
		
		int h = heights[flower];
		
		//Query on tree for getting max value from 1 to height[flower]...
		ll best = query(1,1,h,1,n,tree);
		
		dp[h] = best + beauties[flower] ;
		
		// updating the value....
		update_tree(1,h,1,n,dp[h],tree);
		
	}
	
	ll answer = 0;
	for(auto x : dp)
		max_self(answer,x);
		
	printf("%lld\n",answer);
    return 0;
}
