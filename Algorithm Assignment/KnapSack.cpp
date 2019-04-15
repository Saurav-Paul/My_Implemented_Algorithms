#include<iostream>
#include<vector>
using namespace std;
int main(){
	long long item, knapsack;
	cout<<"Enter the number of items : ";
	cin>>item;
	cout<<"Enter the size of knapsack : ";
	cin>>knapsack;
	vector<pair<long long,long long>> items;
	cout<<"Enter every itmes weight and value :-"<<endl;
	for(int i=0;i<item; i++){
		int weight, value;
		cin>>weight>>value;
		items.push_back(make_pair(weight,value));
	}
	vector<vector<long long>>dp(item+1,vector<long long>(knapsack+1,0));
	for(int i=0; i<item; i++){
		int weight=items[i].first,value=items[i].second;
		for(int j=1;j<=knapsack ; j++){
			if(j<weight)
				dp[i+1][j]=dp[i][j];
			else{
				dp[i+1][j]=max(dp[i][j],dp[i][j-weight]+value);
			}
		}
		
	}
	cout<<"Maximum profit you can get : ";
	cout<<dp[item][knapsack]<<endl;
	
	return 0;
}
