#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6  + 10 ;
int phi[nax] ;
bool mark[nax];

void sieve_phi(int n) {
	for(int i = 1 ; i<= n; i++) phi[i] = i;
	mark[1] = true ;
	
	for(int i = 2 ; i <= n; i+= 2){
		if(i != 2 ) mark[i] = 1;
		phi[i] = phi[i] /  2 ;
	}
	
	for(int i = 3; i <= n; i+= 2){
		if(mark[i] == false ){
			phi[i] = phi[i] - 1;
				
			for(int j =( i << 1) ; j <= n ; j+= i){
				mark[j] = true ;
				phi[j] = phi[j] / i * (i-1)  ;
			}
		}
	}
}

int main() {
	
	sieve_phi(nax-10);
	
	return 0 ;
}
