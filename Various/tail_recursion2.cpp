                    /*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
int sum_ara(int *ara , int index , int result){
	if(index<0){
		return result ; 
	}
	return sum_ara(ara, index-1, result+ara[index] ) ;
}
int main(){
	
	int ara[]={6,4,3,5,3,4,5,6,8} ;
	
	int sum = sum_ara(ara,8,0);
	
	printf("%d\n",sum);
	
	return 0;
}
