
/**
 *    author        : Saurav Paul 
 *    created       : September 11, 2020 2:43 PM
 *    Problem Name  : Meet in the middle 
 *    Complexity    : O(2^(N/2)*N)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;


const int nax = 2e6 + 10 ;

void calsubarray(vector<ll> &a , vector<ll> &x, int base, int st){

    int lim = (1 << base) ;
    for(int mask = 0; mask < lim ; mask ++){
        ll s= 0 ;
        for(int bit = 0 ; bit < base ; bit++){
            if(mask & (1 << bit)){
                s += a[bit+st] ;
            }
        }
        x.push_back(s);
    }
}


ll meet_in_the_middle(vector<ll> &v , int S){

    vector<ll>  X , Y;
    int N = v.size() ;

    Y.push_back(0) ;
    X.push_back(0) ;
    calsubarray(v,X,N/2,0) ;
    calsubarray(v,Y,N-N/2,N/2) ;

    sort(Y.begin(),Y.end()) ;

    ll mx = 0 ;

    for(int i = 0 , sx = X.size(), sy = Y.size(); i < sx; i++){
        if(X[i] > S) continue ;

        int p = lower_bound(Y.begin(),Y.end(),S-X[i]) - Y.begin() ;
        if(p == sy || Y[p] != (S-X[i])) p --;

        mx = max(mx, Y[p] + X[i]) ;
    }

    return mx ;
    
}

void solve(){

    ll N , S ;
    cin >> N >> S ;

    vector<ll> v(N);
    for(auto &x : v){
        cin >> x ;
    }

    ll best = meet_in_the_middle(v,S);
    cout << best << endl ;
}



int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        solve() ;
    }

    return 0 ;
}
