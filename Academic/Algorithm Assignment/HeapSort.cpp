#include<iostream>
#include<vector>
using namespace std;
void HeapSort(vector<int> &nums);
void build_max_heap(vector<int> &nums, int n);
void heapify(vector<int>&nums, int element,int n);
int main(){
	int n,temp;
	cout<<"Enter the number of element : ";
	cin>>n;
	vector<int> nums;
	cout<<"Enter all the element : ";
	for(int i=0; i<n ; i++){
		cin>>temp;
		nums.push_back(temp);
	}
	HeapSort(nums);
	cout<<"After sorting -> ";
	for(auto i : nums)
		cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
void HeapSort(vector<int> &nums){
	int n=nums.size();
	for(int i=0;i<n ; i++){
	build_max_heap(nums,n-i);
	swap(nums[0],nums[n-i-1]);
   }
}
void build_max_heap(vector<int> &nums, int n){
	int limit = n/2-1;
	for(int i=limit ;  i>=0 ; i--){
		int l=2*i+1 ; 
		int r=2*i+2;
		if(l<n){
			if(nums[i]<nums[l]){
				swap(nums[i],nums[l]);
				heapify(nums,l,n);
			}
		}
		if(r<n){
			if(nums[i]<nums[r]){
				swap(nums[i],nums[r]);
				heapify(nums,r,n);
			}
		}
	}
	
}
void heapify(vector<int>&nums, int element,int n){
	
	int l=2*element+1;
	int r=2*element+2;
	if(l<n){
			if(r<n){
				if(nums[r]>nums[l]){
						if(nums[r]>nums[element]){
							swap(nums[r],nums[element]);
							heapify(nums,r,n);
						}
				}
				else{
					if(nums[l]>nums[element]){
						
						swap(nums[l],nums[element]);
						heapify(nums,l,n);
						
					}
					
					
				}
			}
			else{
				
				if(nums[l]>nums[element]){
					
					swap(nums[l],nums[element]);
					heapify(nums,l,n);
				
				}
				
				
			}
		
	}
}
