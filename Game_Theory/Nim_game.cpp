#include<bits/stdc++.h>
using namespace std;

void solve(int caseno){
	int n, m; scanf("%d%d",&n,&m);
	long long int Xor = 0;
	for(int i=  0 ; i < n; i++){
		long long int sum = 0;
		for(int j= 0,temp  ; j < m ; j++){
			scanf("%d",&temp);
			sum += temp;
		}
		Xor ^= sum;
	}
	printf("Case %d: ",caseno);
	if(Xor > 0)
		puts("Alice");
	else
		puts("Bob");
	
	return ;
}

int main(){
	
	int testcase,caseno=0;
	scanf("%d",&testcase);
	while(testcase--)
		solve(++caseno);
		
	return 0;
}
