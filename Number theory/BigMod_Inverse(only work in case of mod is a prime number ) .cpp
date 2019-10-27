            /*Saurav Paul*/
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
