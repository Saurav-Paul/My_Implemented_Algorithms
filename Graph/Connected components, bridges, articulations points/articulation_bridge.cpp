
/**
 *    author        : Saurav Paul 
 *    created       : August 28, 2020 8:57 AM
 *    Problem Name  : Articulation Bridge
 *    Problem Limit : O(N+M)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

/*
   Articulation point (or cut vertex) is defined as a vertex which,
   when removed along with associated edges, makes the graph disconnected (or more precisely,
   increases the number of connected components in the graph).
   The task is to find all articulation points in the given graph.
*/

const int INF = 1e9 + 90 ;
int N , M ;
vector<vector<int>> graph ;

vector<bool> vis ;
int timer = 0 ;
vector<int> low , tin ;
set<pair<int,int>> cut_bridge ;

void dfs(int node , int par = -1){
    vis[node] = true ;
    low[node] = tin[node] = timer++;

    for(auto nxt : graph[node]){
        if(nxt == par) continue ;
        if(vis[nxt]){
            low[node] = min(low[node],tin[nxt]) ;
        }
        else{
            dfs(nxt,node) ;
            low[node] = min(low[node], low[nxt]) ;

            if(low[nxt] > tin[node]){
                int _u = node, _v = nxt ;
                if(_u > _v) swap(_u,_v) ;
                cut_bridge.insert({_u,_v}) ;
            }
        }
    }
}


void find_cut_bridges(){
    vis.assign(N+1,false) ;
    low.assign(N+1,-1) ;
    tin.assign(N+1,-1) ;

    for(int i = 1 ; i <= N ; i++){
        if(!vis[i])
            dfs(i) ;
    }

    cout << cut_bridge.size() << endl ;
    cout << "Articulation Bridges :" <<"\n" ;
    for(auto bridge : cut_bridge){
        cout << bridge.first << "---" << bridge.second << "\n" ;
    }
}


void solve(){
    cin >> N >> M ;

    graph = vector<vector<int>>(N+1) ;

    for(int i = 0 ; i < M ; i++){
        int u , v ;
        cin >> u >> v ;

        graph[u].emplace_back(v) ;
        graph[v].emplace_back(u) ;
    }

    find_cut_bridges() ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
