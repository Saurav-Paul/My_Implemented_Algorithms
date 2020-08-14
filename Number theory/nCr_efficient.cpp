// nCr

const ll SZ = 1e5 + 10;
const ll MOD = 1e9 + 7 ;
vector<ll> fact(SZ+1) ;
ll mod_inverse[SZ+5];
ll BigMod(ll num , ll power, ll mod){
	if(power == 0 ){
		return 1 ;
	}
	ll x = 1 ;
	if(power&1){
		x = num ;
	}
	ll y = BigMod(num,power/2,mod) ;
	y = ( y%mod * y%mod )%mod ;
	return (y%mod * x%mod)%mod ;
}
ll BigModInverse(ll num , ll mod ){
	return BigMod(num,mod-2,mod) ;
}
void precomputation(){
    fact[0] = mmi[0]= 1;
    for(int i = 1 ; i < SZ ; i++){
        fact[i] = (fact[i-1] * i) % MOD ;
        ll x=BigModInverse(fact[i], MOD)%MOD;
        mod_inverse[i]=x;
    }
}
ll nCr(ll num,ll r){
    ll temp =((fact[num]*mod_inverse[r])%MOD)*mod_inverse[num-r];
    temp%=MOD;
    return temp ;
}

// nCr end
