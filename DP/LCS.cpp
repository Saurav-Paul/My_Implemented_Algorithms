#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vl                    vector<ll>
#define SZ(x)                 (x).size()
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
using namespace std;
const ll INF = 2e18 + 99;
typedef pair<ll,ll> Pair;
typedef vector<ll> vll;
bool file=0,rt=1;
clock_t tStart ;
void FAST_IO();
////////////////////////

int main()
{

    FAST_IO();
    ////////////////////////
    string a,b; cin>>a>>b;
    ll alen=a.size(),blen=b.size();
    vector<vector<ll>> dp(alen+1,vector<ll>(blen+1,0));
    for(int i=1; i<=alen ; i++){
        for(int j=1; j<=blen ; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // for(int i=0; i<=alen ; i++){
    //     for(int j=0; j<=blen ; ++j)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<dp[alen][blen]<<endl;
    string ans="";
    ll i=alen,j=blen;
    while(i>0 && j>0){
        if(dp[i][j]==dp[i][j-1]){
            j--;
        }else if(dp[i][j]==dp[i-1][j]){
            i--;
        }else{
            ans.pb(a[i-1]);
            i--;
            j--;
        }
    }
    reverse(all(ans));
    cout<<ans<<endl;
    ////////////////////////
    if(rt && file){
     printf("\nTime taken: %.6fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    }
    return 0;
   }

void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //cout.tie(NULL);
    //cout.setf(ios::fixed);
    //cout.precision(2);
    if(rt && file){ tStart = clock(); }
    if(file){
    #ifndef _offline
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    }
}
