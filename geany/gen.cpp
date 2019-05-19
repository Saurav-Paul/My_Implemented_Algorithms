// generating random sequence of distinct elements
#include<bits/stdc++.h>
using namespace std;

void same_num_not_allowed(int n, int a , int b);
void same_num_allowed(int n, int a, int b);

int rand(int  a, int  b){
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1])); //atoi(s) converts an array of char to int
	int  n=rand(2,20);
	printf("%d\n",n);
	int a=1;
	int b=100;
	
	//generating...
	
	same_num_not_allowed(n,a,b);
	//same_num_allowed(n,a,b);
	
}
void same_num_not_allowed(int n,int a,int b){
	
	set < int > used;
	//generating...
	for(int i= 0 ; i< n; i++){
		int x; 
		do {
			x=rand(a,b);
		} while(used.count(x));
		printf("%d ",x);
		used.insert(x);
	}
	puts("");
}
void same_num_allowed(int n,int a, int b){
	
	multiset < int > used;
	//generating...
	for(int i= 0 ; i< n; i++){
		int x; 
		x=rand(a,b);
		printf("%d ",x);
		used.insert(x);
	}
	puts("");
}
