#include<bits/stdc++.h>
using namespace std;
const int mod = 1e7 + 7;

int fact_tail(int n, int result){
	if(n==0)
		return result;
	return fact_tail(n-1, (n*result)%mod);
}
int fact_optimized(int n){
	return fact_tail(n,1);
}
int main(){
	
	cout << fact_optimized(5) << endl;
	
	
	return 0;
}
