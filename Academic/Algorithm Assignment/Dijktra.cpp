#include<iostream>
using namespace std;
int graph[100][100];
int dist[100],touch[100],ans[100];
void dijktra(int source,int node, int edge)
{
    for(int i=1; i<=node ; i++)
    {
        if(source==i)
        {
            dist[i]=0;
            ans[i]=0;
        }
        else
        {
            dist[i]=graph[source][i];
            ans[i]=dist[i];
        }
        touch[i]=source ;
    }
    for(int i=1;i<=node;i++)
        cout<<dist[i]<< " ";
    cout<<endl;
    int cnt=0;
    while(cnt!=(node-1))
    {

        int minimum = 100 ;
        int vnear;
        for(int i=1; i<=node; i++)
        {
            if(i==source)
                continue ;
            if(dist[i]>=0 && dist[i]<minimum)
            {

                vnear=i;
                minimum=dist[i];

            }

        }
        for(int i=1; i<=node ; i++)
        {
            if(i==source)
            {
                continue ;
            }
            if(dist[vnear] + graph[vnear][i]< dist[i])
            {
                dist[i]=dist[vnear]+ graph[vnear][i];
                touch[i]=vnear;
            }

        }

        ans[vnear]=dist[vnear];
        dist[vnear]=-1;
        cnt++;

    }

}
int main()
{
    int node, edge;
    cout<<"Enter the number of nodes and edges : ";
    cin>>node>>edge;
//Initializing all distance from all node infinity ...
    for(int i=0; i<=node; i++)
    {
        for(int j=0; j<=node ; j++)
        {
            graph[i][j]=100 ;
        }
    }
    cout<<"Insert the edges .. "<<endl;
    for(int i=0; i< edge ; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        graph[x][y]=w;
    }
    int source ;
    cout<<"Enter your source : ";
    cin>>source;
    dijktra(source,node,edge);
    cout<<"The distances from "<<source<<" to nodes :"<<endl;
    for(int i=1; i<=node; i++)
    {
        if(i!=source)
            cout<<source<<"----->"<<i<<"="<<ans[i]<<"|Touch-"<<touch[i]<<endl;
    }
    return 0;
}
