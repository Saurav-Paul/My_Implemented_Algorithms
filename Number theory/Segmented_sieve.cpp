            /*Saurav Paul*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void sieve(vector< ll > &v, ll n){
	ll limit = (ll)sqrt(n) +1;
	
	bool notPrime[limit+1] ;
	memset(notPrime,0,sizeof(notPrime));
	
	//marking all multiple of 2 as true
	for(int i=4 ; i<= limit ; i+=2)
		notPrime[i] = 1;
		
	//finding all primenumber between 1 to limit...
	for(int i= 3 ; i<=limit ; i+=2){
		
		if(!notPrime[i]){
			for(int j=i+i; j<=limit ; j+=i ){
				notPrime[j] = 1;
			}
		}
	}
	
	// taking primes into primeList...
	for(int i=2 ; i<= limit ; i++){
		if(!notPrime[i]){
			v.emplace_back(i);
		}
	}
}

void printPrimes(vector <ll > &v,ll l, ll r){
	

	bool notPrime[r-l+1] ;
	memset(notPrime,0,sizeof(notPrime));
	
	// marking those number , they are not prime between l to r
	for (auto x : v){
		
		if(x*x>r)
			break ;
		ll base = l/x;
		base*=x;
		if(base < l)
			base += x;
		
		
		for(ll i=base ; i<=r ; i+=x){
			notPrime[i-l] = 1;
			
		}
		if(base == x ){
			notPrime[base-l] = 0;
			
		}
		
	}
	// printing the primes between l to r...
	if(l<=1){
		if(l==0)
			notPrime[1] = 1;
		if(l==1)
			notPrime[0] = 1;
	}
	for(ll i=0; i<=r-l; i++){
		
		if(!notPrime[i] ){
			ll temp = i + l;
			printf("%lld\n",temp);
		}
	}
	
	
}

int main(){
	vector< ll > primeList;
	ll nax = 1000000000;

	sieve(primeList,nax);
	
	ll tcase; 
	scanf("%lld",&tcase);
	
	while(tcase--){
		ll l,r ; 
		scanf("%lld%lld",&l,&r);
		
		printPrimes(primeList,l,r);
		puts("");
		
	}
	
	
	return 0;
}
