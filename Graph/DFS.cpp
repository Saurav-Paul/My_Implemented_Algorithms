
/**
 *    author        : Saurav Paul 
 *    created       : August 21, 2020 7:22 PM
 *    Problem Name  : DFS
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

int Node, Edge ;
vector<vector<int>> graph ;
vector<int> vis ;

// dfs Implementation 
void dfs(int node, int parent){
    // code
    vis[node] = 1 ;

    for(auto x : graph[node]){
        if(x == parent || vis[x]) continue ;
        dfs(x,node) ;
    }

    // code
}
// dfs Implementation End

void solve(){
    cin >> Node >> Edge ;

    graph = vector<vector<int>> (Node+1, vector<int>()) ;
    vis = vector<int> (Node+1) ;

    for(int i = 0 ; i < Edge ; i++){
        int u , v;
        cin >> u >> v;
        graph[u].emplace_back(v) ;
        graph[v].emplace_back(u) ;
    }

    int start_node = 1;
    dfs(start_node,start_node) ;
    
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
