#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int white=0,grey=1,black=2;
const int INF=100000;
struct node{
	int color,dist,parent;
};
int main(){
	int nodes,edges;
	cout<<"Enter the number nodes : ";
	cin>>nodes;
	cout<<"Enter the number of edges : ";
	cin>>edges ;
	vector<vector<int>> graph(nodes+1,vector<int>());
	vector<node> Prop(nodes+1,{white,INF,-1});
	cout<<"Enter all the edges :-"<<endl;
	for(int i=0; i<edges; i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	int st_node=1;
	cout<<"Enter your bfs's starting node : ";
	cin>>st_node ;
	while(st_node<1 || st_node>nodes){
		cout<<"Invalid input.Againg input please : ";
		cin>>st_node;
	}
	Prop[st_node].color=grey;
	Prop[st_node].dist=0;
	Prop[st_node].parent=-1;
	queue <int> q;
	q.push(st_node);
	cout<<"Bfs starting from("<<st_node<<") : ";
	while(!q.empty()){
		int p=q.front();
		cout<<"-> "<<p;
		q.pop();
		for(int i=0,sz=graph[p].size() ; i<sz ; i++){
			if(Prop[graph[p][i]].color==white){
				Prop[graph[p][i]].color=grey ;
				Prop[graph[p][i]].dist=Prop[p].dist + 1 ;
				Prop[graph[p][i]].parent= p;
				q.push(graph[p][i]);
			}
			
		}
		Prop[p].color=black ;
		
	}
	
	return 0;
}

