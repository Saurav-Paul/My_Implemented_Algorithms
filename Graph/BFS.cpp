#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <int > vec[100];
bool visited[100];
//s is starting vertex,n is number of vertex
void bfs(int s,int n);
int main(){
int tcase,s,node,edge,i;
cin>>tcase;
while(tcase--){
   // vec.clear();
    cin>>node>>edge;
    int n1,n2;
    for(i=0;i<edge;i++){
       cin>>n1>>n2;
       vec[n1].push_back(n2);
    }
    bfs(0,node);
}
}
void bfs(int s,int n){
for( int i=0;i<n;i++)
    visited[i]=0;
int i;
    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for( i=0;i<vec[u].size();i++){
            int temp=vec[u][i];
            if(visited[temp]==0){
                int v=vec[u][i];
                visited[v]=1;
                q.push(v);
            }
        }
    }

}
