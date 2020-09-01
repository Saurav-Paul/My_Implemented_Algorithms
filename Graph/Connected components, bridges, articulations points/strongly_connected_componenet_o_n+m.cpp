
/**
 *    author        : Saurav Paul 
 *    created       : September 01, 2020 3:01 PM
 *    Problem Name  : Strongly Connected Component (SCC)
 *    Complexity    : O(N+M)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

vector<vector<int>> graph, rev_graph , scc ;
int N , M ;
vector<bool> vis ;
vector<int> order, components ;


void dfs1(int node){
    vis[node] = true ;
    
    for(auto to : graph[node]){
        if(!vis[to]) dfs1(to) ;
    }

    order.push_back(node) ;

}

void dfs2(int node){
    vis[node] = true ;
    components.push_back(node) ;

    for(auto to : rev_graph[node]){
        if(!vis[to]) dfs2(to) ;
    }
}

void find_scc(){
    // 1 - based implementation
    vis.assign(N+1,false) ;
    for(int i = 1; i <= N ; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    vis.assign(N+1,false) ;
    for(int i = order.size()-1 ; i >= 0 ; i--){
        int curr = order[i] ;
        if(!vis[curr]){
            components.clear() ;
            dfs2(curr) ;
            scc.push_back(components) ;
        }
    }
    for(auto comp : scc){
        for(auto x : comp){
            cout << x << " " ;
        }
        cout << endl ;
    }
}

void solve(){
    cin >> N >> M ;


    graph.assign(N+1,vector<int>()) ;
    rev_graph.assign(N+1,vector<int>()) ;

    for(int i = 0 ; i < M ; i++){
        int u , v;
        cin >> u >> v;
        graph[u].emplace_back(v) ;
        rev_graph[v].emplace_back(u) ;
    }

    find_scc() ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        solve() ;
    }

    return 0 ;
}
