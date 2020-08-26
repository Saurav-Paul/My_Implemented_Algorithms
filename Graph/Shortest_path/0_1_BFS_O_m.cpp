
/**
 *    author        : Saurav Paul 
 *    created       : August 25, 2020 11:40 AM
 *    Problem Name  : 0_1 BFS to find single source shortest path
 *    Complexity    : O(m)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;


/*
    complexity of this implementation is just m(number of edge) .
    but it only works if weights is just 0 or 1.
*/

const int INF = 1e9 + 90 ;
int N , M , S , T ;

vector<vector<pair<int,int>>> graph ;
vector<int> dist , parent ;

void path_print(){
    vector<int> path ;

    for(int v = T ; v != -1 ; v = parent[v]) path.push_back(v) ;
    reverse(path.begin(),path.end()) ;

    for(auto x : path) cout << x <<" " ;
    cout << endl ;
}

void _0_1_BFS(){
    dist.assign(N+1,INF) ;
    parent.assign(N+1,-1) ;

    deque<int> dq ;
    dq.push_front(S) ;

    dist[S] = 0 ;
    while(!dq.empty()){
        int curr = dq.front() ;
        dq.pop_front() ;

        for(auto x : graph[curr]){
            int nxt = x.first ;
            int cost = x.second ;
            if(dist[nxt] > dist[curr]+cost){
                dist[nxt] = dist[curr] + cost ;
                parent[nxt] = curr ;
                if(cost == 1){
                    dq.push_back(nxt) ;
                }
                else{
                    dq.push_front(nxt) ;
                }
            }
        }
    }

    if(dist[T] == INF){
        cout << -1 << "\n" ;
    }
    else{
        cout << dist[T] << "\n" ;
        path_print();
    }

}

void solve(){
    cin >> N >> M ;
    cin >> S >> T ;

    graph = vector<vector<pair<int,int>>> (N+1) ;
    for(int i = 0 ; i < M ; i++){
        int u , v , w ;
        cin >> u >> v >> w;

        // directed graph
        graph[u].emplace_back(v,w) ;
    }

    
    _0_1_BFS() ;
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
