#include<iostream>
#include<vector>
using namespace std;
int node;
vector<int>vec[100];
bool mark[100];
void dfsvisit(int cnode);
void dfs();
int main()
{
    cout<<"Enter the total number of node : ";
    cin>>node;
    int edge;
    cout<<"Enter total number of edge : ";
    cin>>edge;
    cout<<"Enter all the edges : "<<endl;
    for(int i =0 ; i<edge; i++)
    {
        cout<<"\nedge "<<i+1<<": ";
        int node1,node2;
        cin>>node1>>node2;
        node1--;
        node2--;
        vec[node1].push_back(node2);
        vec[node2].push_back(node1);
    }
    /*
    cout<<"\nall the nodes : "<<endl;
    for(int i=0;i<node;i++){
            cout<<i+1<<"-> ";
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]+1<<" ";
        }
    cout<<endl;

    }
    */
//calling dfs search
    dfs();
    return 0;
}
void dfs()
{
    cout<<"I am calling "<<endl;
//need to define all mark as zero,
//but it is global so already zero
    for(int i=0; i<node; i++)
    {
        if(mark[i]==0)
        {
            dfsvisit(i);
        }
    }
}

void dfsvisit(int cnode)
{
    //marking as visited
    mark[cnode]=1;
    for(int i=0; i<vec[cnode].size(); i++)
    {
        int n=vec[cnode][i];
        if(mark[n]==0)
        {
            dfsvisit(n);
        }
    }
}
