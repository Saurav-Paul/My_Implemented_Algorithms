#include<iostream>
#include<vector>
using namespace std;
void HeapOperation(vector<int> &nums);
void build_max_heap(vector<int> &nums, int n);
void heapify(vector<int>&nums, int element,int n);
void Delete_Heap_element(vector<int> &nums, int node);
void Insert_Heap_element(vector<int> &nums, int newNode);
int find_parent(int n);
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
	HeapOperation(nums);
	
	return 0;
}
void HeapOperation(vector<int>&nums){
	cout<<"After max heap Building your tree : ";
	build_max_heap(nums,nums.size());
	for(auto i : nums)
		cout<<i<<" ";
	cout<<endl;
	while(1){
	cout<<endl;
	cout<<"For delete an element enter 0, for insert enter 1 , for exit enter 5 : "; 
	int temp;
	cin>>temp;
	if(temp==5){
		break;
	}
	if(temp==0){
		int sz= nums.size();
		if(!sz){
			cout<<"There is not any element in this heap, so you cant't delete any."<<endl;
			continue ;
		}
		cout<<"Enter the node you want to delete : ";
		int node; cin>>node;
		node--;
		while(node>=sz || node<0){
			cout<<"Invalid node , Enter again : ";
			cin>>node;
		}
		Delete_Heap_element(nums,node);
		cout<<"After deleting current heap : ";
		for(auto i : nums)
			cout<<i<<" ";
		cout<<endl;
		
	}
	if(temp==1){
		cout<<"Enter the element you want to insert : ";
		int newNode;
		cin>>newNode;
		Insert_Heap_element(nums,newNode);
		
		cout<<"After Inseting current heap : ";
		for(auto i : nums)
			cout<<i<<" ";
		cout<<endl;
		
	}
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

void Delete_Heap_element(vector<int> &nums, int node){
	int n=nums.size();
	n--;
	swap(nums[node],nums[n]);
	nums.pop_back();
	n--;
	if(n<0)
		return ;
	heapify(nums,node,nums.size());
	
}
void Insert_Heap_element(vector<int> &nums, int newNode){
	nums.push_back(newNode);
	int n=nums.size(); n--;
	int parent=find_parent(n);
	while(nums[parent]<nums[n]){
		swap(nums[parent],nums[n]);
		n=parent;
		if(n==0)
			break;
		parent=find_parent(n);
		
	}
	
}
int find_parent(int n){
	if(n&1)
		return n/2;
	else
		return n/2-1;
}
