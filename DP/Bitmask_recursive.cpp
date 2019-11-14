#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define boost				  ios_base::sync_with_stdio(0);cin.tie(NULL);
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define all(p)                p.begin(),p.end()
#define iscn(num)             scanf("%d",&num);
#define scn(num)              scanf("%lld",&num);
#define scn2(num,num2)        scanf("%lld%lld",&num,&num2);
#define dbg(x)                cerr <<"( "<<#x << " = " << x << " )"<<endl
using namespace std;
void set_bit(ll &N, int pos) { N=N | (1 << pos);}
void reset_bit(int &N, int pos) { N=N & ~(1 << pos);}
bool check_bit(int N,int pos) {return (bool)( N&(1 << pos));}
template <class T > void max_self(T &a, T b){
	a=max(a,b);
}
template <class T > void min_self(T &a, T b){
	a=min(a,b);
}
////////////////////////
const ll mod =1e9+7;
const ll INF = 2e18 + 99;
typedef pair<ll,ll> Pair;
typedef vector<ll> vec;;

void ara_read(vec &v,ll n){
	ll temp;
	for(ll i=0; i< n; i++){
		scanf("%lld",&temp);
		v.emplace_back(temp);
	}
}
////////////////////////
int compatible[25][25];
const ll nax =(1<<21) +5;
ll dp[nax][25] ;
void sum_self(ll &a, ll b){
	a+=b ;
	if(a>=mod)
		a-=mod;
}
ll find_way(int n,int curr ,ll mask){
	if(curr==n)
		return 1;
	if(dp[mask][curr]!=-1)
		return dp[mask][curr];
	
	ll ways=0,temp;
	for(int i=0; i< n; ++i){
		if(compatible[curr][i] && !check_bit(mask,i)){
			temp = mask;
			set_bit(mask,i);
			sum_self(ways,find_way(n,curr+1,mask));
			mask =temp ;
		}
	}
	
	return dp[mask][curr]=ways;
}
int main()
{
	/* We can use bitmasking to solve this dp problem
	 * This is a very easy bitmasking problem */
	 int n;
	 memset(dp,-1,sizeof(dp));
	 scanf("%d",&n);
	 for(int i=0; i< n; ++i){
		 for(int j=0; j< n; ++j){
			 scanf("%d",&compatible[i][j]);
		 }
	 }
	ll mask =0;
	ll ways = find_way(n,0,mask);
	printf("%lld\n",ways);
    return 0;
}
