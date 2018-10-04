#include<iostream>
#include<vector>
using namespace std;
vector<int > vec;
void selection_sort();
int main()
{
    int n;
    cout<<"Enter the number of element of your array : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    selection_sort();
    for(int k=0; k<vec.size(); k++)
        cout<<vec[k]<<" ";
    return 0;
}
void selection_sort()
{
    for(int i=0; i<vec.size()-1; i++)
    {
        for(int j=i+1; j<vec.size(); j++)
        {
            if(vec[i]>vec[j])
                swap(vec[i],vec[j]);
        }
    }
}
