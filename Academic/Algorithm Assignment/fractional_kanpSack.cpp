#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct prop{
	double ratio,weight,profit;
	
};
bool custom_sort(prop a, prop b){
	return a.ratio>b.ratio ;
}
int main(){
	long long item,knapsack;
	cout<<"Enter the number of items : ";
	cin>>item;
	cout<<"Enter the size of your knapsack : ";
	cin>>knapsack;
	vector<prop>items;
	cout<<"Enter all items weight and profit :-"<<endl;
	for(int i=0; i< item ; i++){
		double w,p;
		prop temp;
		cin>>w>>p;
		temp.ratio=p/w;
		temp.weight=w;
		temp.profit=p;
		items.push_back(temp);
	}
	sort(items.begin(),items.end(),custom_sort);
	long long weight=0;
	double ans=0;
	for(auto i : items){
		if(weight<knapsack){
			double temp=knapsack-weight;
			temp=min((double)temp,i.weight);
			cout<<temp<<endl;
			ans+=(temp*i.ratio);
			weight+=temp;
		}
		else
			break ;
	}
	cout<<"Maximum profit you can get : "<<ans<<endl;
	return 0;
}
