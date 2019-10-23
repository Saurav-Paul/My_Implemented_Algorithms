                    /*Saurav Paul*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int > vec;
struct range
{
    int start,stop;
};
stack<range> stck;
void quick_sort();
struct range trng;
int main()
{
    struct range rng;
    int n;
    cout<<"Enter the number of element of your array : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    rng.start=0;
    rng.stop=n-1;
    stck.push(rng);
    quick_sort();
for(int k=0;k<vec.size();k++)
    cout<<vec[k]<<" ";
    return 0;
}
void quick_sort()
{
    while(!stck.empty()){
    trng=stck.top();
    int st=trng.start;
    int sp=trng.stop;
    stck.pop();
    int  i=st;
    int   j=sp;
    int flag =1;
    while(i!=j)
    {
        if(vec[i]<vec[j] &&flag)
            j--;
        else if(vec[i]<vec[j] && !flag)
            i++;
        else
        {
            swap(vec[i],vec[j]);
            if(flag)
                flag=0;
            else
                flag=1;
        }
    }
    if(i-st>1){
        struct range temp;
        temp.start=st;
        temp.stop=i-1;
        stck.push(temp);
    }
    if(sp-i>1){
        struct range temp;
        temp.start=i+1;
        temp.stop=sp;
        stck.push(temp);
    }
}
return ;
}
