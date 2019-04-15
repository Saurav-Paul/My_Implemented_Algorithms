#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool custom_sort(pair<long long,long long> a, pair<long long,long long> b){
	return a.second<b.second;
}

int main(){
	long long int n;
	cout<<"Enter the number of activity : ";
	cin>>n;
	cout<<"Enter all activities staring and ending time :-"<<endl;
	vector<pair<long long,long long>> activities ,ans;
	for(int i=0; i<n ; i++){
		long long st, sp;
		cin>>st>>sp;
		activities.push_back(make_pair(st,sp));
	}
	sort(activities.begin(),activities.end(),custom_sort);
	ans.push_back(make_pair(activities[0].first,activities[0].second));
	long long sp=activities[0].second;
	for(int i=1; i<n;i++){
		if(activities[i].first>=sp){
			ans.push_back(activities[i]);
			sp=activities[i].second;
		}	
	}
	cout<<"All possible non-conflicting activities are :- "<<endl;
	for(auto i: ans){
		cout<<i.first<<"----"<<i.second<<endl;
	}
	
	return 0;
}
