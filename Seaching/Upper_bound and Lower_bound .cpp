				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &v,int value){
	int low = 0 , high = (int) v.size();
	while(low < high){
		int mid = low + ((high - low) >> 1);
		if(v[mid] < value ) low = mid + 1;
		else high = mid ;
	}
	return low ;
}
int upperbound(vector<int> &v,int value){
	int low = 0 , high = (int) v.size();
	while(low < high){
		int mid = low + ( ( high-low) >> 1 );
		if(v[mid] <= value) low = mid + 1;
		else high = mid ;
	}
	return low;
}
int main()
{
	vector<int> v={1,2,2,2,2,3,4,5,5,6,6,7,8,9,123};
	
	int lo = lowerbound(v,2);
	int hi = upperbound(v,2);
	
	cout << lo <<" "<< hi << endl;

    return 0;
}
