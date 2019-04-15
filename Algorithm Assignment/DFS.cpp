#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int white=0,grey=1,black=2;
const int INF=100000,Nil=-1;
int timecnt=0;
struct node{
	int color,discovery,done,parent;
};
void dfs(vector<vector<int>> &graph,int nodes, vector<node> &Prop);
void dfs_visit(vector<vector<int>> &graph,int u, vector<node> &Prop);
int main(){
	int nodes,edges;
	cout<<"Enter the number nodes : ";
	cin>>nodes;
	cout<<"Enter the number of edges : ";
	cin>>edges ;
	vector<vector<int>> graph(nodes+1,vector<int>());
	vector<node> Prop(nodes+1,{white,INF,INF,-1});
	cout<<"Enter all the edges :-"<<endl;
	for(int i=0; i<edges; i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	cout<<"Dfs order : ";
	dfs(graph,nodes,Prop);
	
	return 0;
}
void dfs(vector<vector<int>> &graph,int nodes, vector<node> &Prop){
	
	for(int i=0; i<=nodes ; i++){
		Prop[i].color=white ;
		Prop[i].parent=Nil;
	}
	timecnt=0;
	for(int i=1; i<=nodes ; i++){
		if(Prop[i].color==white){
			dfs_visit(graph,i,Prop);
		}
	}
	
	
}
void dfs_visit(vector<vector<int>> &graph,int u, vector<node> &Prop){
	cout<<" ->"<<u;
	timecnt++;
	Prop[u].discovery=timecnt;
	Prop[u].color=grey;
	for(int i=0,sz=graph[u].size(); i<sz ; i++){
		int n=graph[u][i];
		if(Prop[n].color==white){
			Prop[n].parent=u;
			dfs_visit(graph,n,Prop);
		}
		
	}
	Prop[u].color=black;
	timecnt++;
	Prop[u].done=timecnt;
	
}
