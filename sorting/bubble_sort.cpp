#include<iostream>
#include<vector>
using namespace std;
vector<int > vec;
void bubble_sort();
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
    bubble_sort();
    for(int k=0; k<vec.size(); k++)
        cout<<vec[k]<<" ";
    return 0;
}
void bubble_sort()
{
    for(int i=0; i<vec.size(); i++)
    {
        for(int j=0; j<vec.size()-1; j++)
        {
            if(vec[j]>vec[j+1])
                swap(vec[i],vec[j]);
        }
    }
}

