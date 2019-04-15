#include<iostream>
#include<vector>
using namespace std;
const int INF=100000;
int main(){
	cout<<"Enter the number of nodes : ";
	int nodes, edges;
	cin>>nodes;
	int graph[nodes+1][nodes+1],dist[nodes+1][nodes+1];
	cout<<"Enter the number of edges : ";
	cin>>edges;
	for(int i=0; i<=nodes ; i++){
		for(int j=0; j<=nodes ; j++){
			if(i==j)
				graph[i][j]=0;
			else
				graph[i][j]=INF;
		}
	}
	cout<<"Enter your edges ->"<<endl;
	for(int i=0; i<edges; i++){
	int a, b,w;
	cin>>a>>b>>w;
	graph[a][b]=w;
	}
	// copying graph value to dist 
	for(int i=0; i<=nodes ; i++){
		for(int j=0;j<=nodes; j++){
			dist[i][j]=graph[i][j];
		}
	}
	//applying floyd warshall
	for(int k=1; k<=nodes; k++){
		for(int i=1; i<=nodes ; i++){
			for(int j=1; j<=nodes; j++){
					if(dist[i][k] +dist[k][j] < dist[i][j])
						dist[i][j]=dist[i][k] + dist[k][j] ;
			}
		}
	}
	//printing all pair possible shortest path
	for(int i=1; i<=nodes ; i++){
		cout<<"Nodes "<<i<<" to all pairs minimum distance :- "<<endl;
		for(int j=1; j<=nodes ; j++){
			cout<<j<<" -> ";
			if(dist[i][j]==INF)
				cout<<"INF"<<endl;
			else
				cout<<dist[i][j]<<endl;
		}
	}
	return 0;
}
