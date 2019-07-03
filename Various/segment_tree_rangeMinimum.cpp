			/*Saurav Paul*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define boost		      ios_base::sync_with_stdio(0);
#define eb                    emplace_back
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1e9+7
#define itoc(c)               ((char)(((int)'0')+c))
#define ctoi(c)               ((int)(((int)c)-'0'))
#define all(p)                p.begin(),p.end()
#define iscn(num)             scanf("%d",&num);
#define scn(num)              scanf("%lld",&num);
#define scn2(num,num2)        scanf("%lld%lld",&num,&num2);
using namespace std;
///////////////////////

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef PAUL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
////////////////////////

template<typename T>T set_bit(T N,T pos){return N=N | (1<<pos);}
template<typename T>T reset_bit(T N,T pos){return N= N & ~(1<<pos);}
template<typename T> bool check_bit(T N,T pos){return (bool)(N & (1<<pos));}
template<typename T>void bin_print(T N){bitset<25>bit(N);cerr<<bit.to_string()<<"\n";}
template<typename T> void max_self(T &a, T b){
	a=max(a,b);
}
template <typename T > void min_self(T &a, T b){
	a=min(a,b);
}
template <typename T > void add_self(T &a, T b){
	a+=b;
}
////////////////////////

template<typename T> void ara_read(T &v,ll n){
	ll temp;
	for(ll i=0; i< n; i++){
		scanf("%lld",&temp);
		v.emplace_back(temp);
	}
}
template<typename T> void ara_print(T &v){
	for(ll x : v)
		printf("%lld ",x);
	puts("");
}
////////////////////////
const int INF = 1e9 + 99;
typedef pair<ll,ll> Pair;
typedef vector<int> vec;;

void build_segment_tree(int node , int st , int sp,vec &v , vec &tree){
	if(st==sp){
		tree[node] = v[st] ;
		return ;
	}
	int lft = 2*node;
	int rght = 2*node +1 ;
	int mid = (st+sp)/2;
	
	build_segment_tree(lft,st,mid,v,tree);
	build_segment_tree(rght,mid+1,sp,v,tree);
	
	tree[node] = min(tree[lft],tree[rght]);
	return ;
}
int query(int node, int a, int b, int st , int sp ,vec &v , vec &tree){
	
	if(sp < a || st> b)
		return INF ;
	if(st >= a && b >= sp){
		return tree[node];
	}
	int lft = 2 *node;
	int rght = 2*node +1;
	int mid = (sp+st) / 2;
	
	int temp1 = query(lft,a,b,st,mid,v,tree);
	int temp2 = query(rght,a,b,mid+1,sp,v,tree);
	
	return min(temp1,temp2);
}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	int caseno=0;
	while(testcase--){
		int n, q;
		scanf("%d%d",&n,&q);
		vector <int > num(n+1);
		for(int i=1; i<= n; i++)
			scanf("%d",&num[i]);
		//building segment tree with minimum value in range...
		vector <int > tree(n*3);
		
		build_segment_tree(1,1,n,num,tree);
		
		// reading query...
		printf("Case %d:\n",++caseno);
		while(q--){
			int a , b;
			scanf("%d%d",&a,&b);
			// query on segment tree...
			int mini = query(1,a,b,1,n,num,tree);
			printf("%d\n",mini);
		}
	}
    return 0;
}
