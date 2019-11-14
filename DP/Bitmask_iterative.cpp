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
template<class T >T set_bit(T N,T pos){return N=N | (1<<pos);}
template<class T >T reset_bit(T N,T pos){return N= N & ~(1<<pos);}
template<class T > bool check_bit(T N,T pos){return (bool)(N & (1<<pos));}
template <class T > void max_self(T &a, T b){
	a=max(a,b);
}
template <class T > void min_self(T &a, T b){
	a=min(a,b);
}
////////////////////////

const ll INF = 2e18 + 99;
typedef pair<ll,ll> Pair;
typedef vector<int> vec;;

void ara_read(vec &v,ll n){
	ll temp;
	for(ll i=0; i< n; i++){
		scanf("%lld",&temp);
		v.emplace_back(temp);
	}
}
void print_ara(vec &v){
	for(ll x : v)
		printf("%lld ",x);
	puts("");
}
////////////////////////

void add_self(int &a, int b){
	a+=b;
	if(a>MOD)
		a-=MOD;
}

int main()
{
	int n; scanf("%d",&n);
	int com[n][n];
	const int nax = (1<<n) ;
	loop(i,0,n-1){
		loop(j,0,n-1){
			scanf("%d",&com[i][j]);
		}
		
	}
	vector < int > dp(nax);
	dp[0] = 1;
	loop(mask,0,nax-2){
		int cnt = __builtin_popcount(mask);
		loop(x,0,n-1){
			if(com[cnt][x] && !check_bit(mask,x)){
				int temp = mask ^ (1 << x);
				add_self(dp[temp],dp[mask]);
			}
		}
	}
	
	printf("%d\n",dp[nax-1]);
	
    return 0;
}
