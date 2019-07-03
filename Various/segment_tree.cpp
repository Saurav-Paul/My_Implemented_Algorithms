#include<bits/stdc++.h>
using namespace std;
const int nax = 15;
int ara[] = {0,1,2,3,5,3,2,5,2,3,5, 5,3,23,45,5};
vector <int > tree(3*nax) ;


void build_segment_tree(int node, int st , int sp){
	
	if(st==sp){
		tree[node] = ara[st];
		return ;
	}
	int lft = node * 2;
	int rght = node * 2 +1;
	int mid = (st + sp)/2 ;
	build_segment_tree(lft,st, mid);
	build_segment_tree(rght,mid+1,sp);
	
	tree[node] = tree[lft] + tree[rght] ;
}
int  query(int node , int a ,int b,int st , int sp){
		
		if(a > sp || b < st)
			return 0;
		if(st>=a && sp<=b)
			return tree[node];
			
		int lft = 2 * node;
		int rght = 2 * node + 1;
		int mid = (st+sp)/2;
		int ans = query(lft,a,b,st,mid);
		ans += query(rght,a,b,mid+1,sp);
		
		return ans;
	
}
void update_tree(int node, int index , int st , int sp, int newValue){
	
	if (sp < index || st > index)
		return ;
		
	if (st==sp){
		tree[node] = newValue;
		return ;
	}
	int lft = 2*node ;
	int rght = 2 *node + 1;
	int mid = (sp+st) / 2;
	update_tree(lft,index,st,mid,newValue);
	update_tree(rght,index,mid+1 ,sp, newValue);
	
	tree[node] = tree[lft] + tree[rght] ;
	return ;
}
int main(){
	
	//building segment tree ...
	build_segment_tree(1,1,15);
	printf("\t\t\t/*Segment-Tree*/\n\n");
	int q;
	printf("What is the number of query : ");
	scanf("%d",&q);
	puts("");
	while(q--){
		int a,b;
		int x ;
		printf("Enter 1 for update and 2 for search : ");
		scanf("%d",&x);
		if(x==2){
			printf("Enter range a and b : ");
			scanf("%d%d",&a,&b);
			int ans =  query(1,a,b,1,15);
			printf("sum of element between %d to %d = %d\n",a,b,ans);
		}
		else{
			printf("Enter the index and new-value :");
			int index, newValue ;
			scanf("%d%d",&index, &newValue);
			update_tree(1,index,1,15,newValue);
		}
		puts("");
	}
	
	return 0;
}
