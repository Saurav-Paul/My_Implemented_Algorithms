
/**
 *    author        : Saurav Paul 
 *    created       : August 28, 2020 8:57 AM
 *    Problem Name  : Finding connected componenet
 *    Problem Limit : O(N+M)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 90 ;
int N , M ;

vector<vector<int>> graph ;
vector<bool> vis ;
vector<int> componenet ;

void dfs(int node){
    vis[node] = true ;
    componenet.push_back(node) ;

    for(auto nxt : graph[node]){
        if(!vis[nxt]){
            dfs(nxt) ;
        }
    }
}

void solve(){
    cin >> N >> M ;

    graph = vector<vector<int>>(N+1) ;
    vis.assign(N+1,false) ;

    for(int i = 0 ; i < M ; i++){
        int u , v ;
        cin >> u >> v ;

        graph[u].emplace_back(v) ;
        graph[v].emplace_back(u) ;
    }

    for(int i = 1; i <= N ; i++){
        if(!vis[i]){
            componenet.clear() ;
            dfs(i) ;
            cout << "Component : " ;
            for(auto x : componenet) cout << x << " " ;
            cout << endl ;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
