#include<iostream>
#include<vector>
using namespace std;
void QuickSort(vector<int> elements,vector<int> &sorted,int st , int sp);

int main(){
	int n ,temp; 
	cout<<"Enter the number of  element : ";
	cin>>n;
	vector<int>elements,sorted;
	cout<<"Enter all the elements : ";
	for(int i=0; i< n ; i++){
		cin>>temp;
		elements.push_back(temp);
	}
	QuickSort(elements,sorted,0,n-1);
	cout<<"After sorted -> ";
	for(auto i : sorted)
		cout<<i<<" ";
	cout<<endl;
	
	return 0;
}

void QuickSort(vector<int> elements,vector<int> &sorted,int st , int sp){
	if(st>sp)
		return ;
	if(st==sp){
		sorted.push_back(elements[st]);
		return ;
	}
	int pivot=sp;
	for(int i=st ; i<pivot ; i++){
		if(elements[i]>elements[pivot]){
			if(pivot-i==1){
				swap(elements[i],elements[pivot]);
				break;
			}else{
				swap(elements[i],elements[pivot-1]);
				swap(elements[pivot],elements[pivot-1]);
				pivot=pivot-1;
				i--;
			}
		}
	}
	QuickSort(elements,sorted,st,pivot-1);
	sorted.push_back(elements[pivot]);
	QuickSort(elements,sorted,pivot+1,sp);
	
}
