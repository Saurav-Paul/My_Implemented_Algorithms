#include<iostream>
#include<string>
using namespace std;
int cnt=0;
void permutation(string text,int left,int right);
int main()
{
    string text;
    cin>>text;
    cnt=0;
    int tsize=text.size();
    permutation(text,0,tsize-1);


    return 0;
}
void permutation(string text,int left,int right)
{

    if(right==left)
    {
        cout<<text<<endl;
        return ;
    }

    for( int i=left; i<=right; i++)
    {
        swap(text[i],text[left]);
        permutation(text,left+1,right);
        swap(text[i],text[left]);

    }

}
