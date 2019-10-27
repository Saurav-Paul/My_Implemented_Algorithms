#include<iostream>
#include<vector>
using namespace std;
int bin_search(vector<int> &ara,int st, int sp, int num);
int main(){
	int n;
	cout<<"Enter the number of elements you have : ";
	cin>>n;
	vector<int> ara;
	int temp;
	cout<<"Enter all the elements : ";
	for(int i=0; i< n ; i++){
		cin>>temp;
		ara.push_back(temp);
	}
	cout<<"Write the element you want to search : ";
	while(cin>>temp){
		int ans=bin_search(ara,0,n-1,temp);
		if(ans==-1)
			cout<<"Element not found in the array."<<endl;
		else
			cout<<"Element found at "<<ans<<" ."<<endl;
		cout<<"Write the element you want to search : ";
	}
	return 0;
}
int bin_search(vector<int> &ara,int st, int sp, int num){
	int mid=(st+sp)/2;
	if(ara[mid]==num)
		return mid+1;
	else if(num>ara[sp] || num<ara[st] )
		return -1;
	else if(num>ara[mid])
		return bin_search(ara,mid+1,sp,num);
	else 
		return bin_search(ara,st,mid,num);
}
