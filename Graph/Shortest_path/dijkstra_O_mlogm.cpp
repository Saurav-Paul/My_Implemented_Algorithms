
/**
 *    author        : Saurav Paul 
 *    created       : August 25, 2020 11:40 AM
 *    Problem Name  : Dijkstra Algorithm Implementation
 *    Complexity    : O(m log  m)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 90 ;
int N , M , S , T ;

class Node{
    public :
        int node , cost ;
        Node(int _node , int _cost){
            node = _node , cost = _cost ;
        }
};

bool operator<(Node A , Node B){
    return A.cost > B.cost ;
}

vector<vector<pair<int,int>>> graph ;
vector<int> dist , parent ;

void path_print(){
    vector<int> path ;

    for(int v = T ; v != -1 ; v = parent[v]) path.push_back(v) ;
    reverse(path.begin(),path.end()) ;

    for(auto x : path) cout << x <<" " ;
    cout << endl ;
}

void Dijkstra(){
    dist.assign(N+1,INF) ;
    parent.assign(N+1,-1) ;

    priority_queue<Node> PQ ;

    // pushing starting node
    PQ.push(Node(S,0)) ;
    dist[S] = 0 ;

    while(!PQ.empty()){
        Node curr = PQ.top() ;
        PQ.pop() ;

        // means it already visited
        if(curr.cost != dist[curr.node]) continue ;

        for(auto e : graph[curr.node]){
            int nxt = e.first ;
            int cost = e.second ;

            if(curr.cost + cost < dist[nxt]){
                dist[nxt] = curr.cost + cost ;
                PQ.push(Node(nxt, curr.cost + cost)) ;
                parent[nxt] = curr.node ;
            }
        }
    }

    if(dist[T] == INF) cout << -1 << endl ;
    else {
        cout << dist[T] << "\n" ;
        path_print() ;
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

    Dijkstra() ;
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
