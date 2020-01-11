            /*Saurav Paul*/
long long int BigMod(long long int num , long long int power, long long int mod){
	
	if(power == 0 ){
		return 1 ;
	}
	long long int x = 1 ;
	if(power&1){
		x = num ;
	}
	long long int y = BigMod(num,power/2,mod) ;
	y = ( y%mod * y%mod )%mod ;
	return (y%mod * x%mod)%mod ;
}
