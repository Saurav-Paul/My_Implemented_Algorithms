                    /*Saurav Paul*/
#include<iostream>
#include<vector>
using namespace std;
vector<int > vec;
void insertion_sort();
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
    insertion_sort();
    for(int k=0; k<vec.size(); k++)
        cout<<vec[k]<<" ";
    return 0;
}
void insertion_sort()
{  int i, key, j;
   for (i = 1; i < vec.size(); i++)
   {
       key = vec[i];
       j = i-1;

       while (j >= 0 && vec[j] > key)
       {
           vec[j+1] = vec[j];
           j = j-1;
       }
       vec[j+1] = key;
   }
}
