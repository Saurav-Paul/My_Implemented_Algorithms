#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,temp;
	cout<<"Enter the number of element : ";
	cin>>n;
	vector<int> nums;
	cout<<"Enter all the elements : ";
	for(int i=0; i< n; i++){
		cin>>temp;
		nums.push_back(temp);
		int j=i;
		while(j>0){
			if(nums[j]<nums[j-1]){
				swap(nums[j],nums[j-1]);
			}
			else{
				break;
			}
			j--;
		}
	}
	cout<<"Sorted Array -> ";
	for(auto i : nums )
		cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
