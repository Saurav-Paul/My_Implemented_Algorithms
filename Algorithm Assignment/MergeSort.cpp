#include<iostream>
#include<vector>
using namespace std;
void merge_sort(vector<int>&ara,int left, int right);
void merging(vector<int>&ara,int left, int mid, int right);
int main()
{
    int n;
    cout<<"Enter the number of element : ";
    cin>>n;
	vector<int> ara(n,0);
    cout<<"Enter all the element : ";
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    merge_sort(ara,0,n-1);
    cout<<"After sorting : ";
    for(auto i : ara)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
void merge_sort(vector<int>&ara,int left, int right)
{
    int mid=left+right;
    mid/=2;
    if(right>left)
    {
        merge_sort(ara,left,mid);
        merge_sort(ara,mid+1,right);
        merging(ara,left,mid,right);
    }
}
void merging(vector<int>&ara,int left, int mid, int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int tempara1[n1],tempara2[n2];

    for(int i=0; i<n1; i++)
    {
        tempara1[i]=ara[left+i];
;
    }

    for(int i=0; i<n2; i++)
    {
        tempara2[i]=ara[mid+1+i];

    }
    
    int i=0,j=0,temp=left;
    
    while(i<n1 && j<n2)
    {

        if(tempara1[i]<tempara2[j])
        {
            ara[temp]=tempara1[i];
            i++;
            temp++;
        }
        else{
           ara[temp]=tempara2[j];
            j++;
            temp++;
        }

    }
    while(i<n1)
    {
        ara[temp]=tempara1[i];
        i++;
        temp++;
    }
    while(j<n2)
    {
        ara[temp]=tempara2[j];
        j++;
        temp++;

    }

}
