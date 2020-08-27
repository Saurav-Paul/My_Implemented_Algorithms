
/**
 *    author        : Saurav Paul 
 *    created       : August 25, 2020 11:40 AM
 *    Problem Name  : Bellman-ford Implemenation
 *    Complexity    : O(nm)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 90 ;
int N , M , S , T ;

class Edge{
    public :
    int u , v, w ;
    Edge(int _u, int _v , int _w){
        u = _u , v = _v , w = _w ;
    }
};
vector<Edge> graph ;
vector<int> dist , parent ;

void path_printing(int last_node){

    vector<int> path ;
    for(int cur = last_node ; cur != -1 ; cur = parent[cur]){
        path.emplace_back(cur) ;
    }

    reverse(path.begin(),path.end()) ;
    cout << "Path : " ;
    for(auto x : path) cout << x <<" " ;
    cout << endl ;
}

void Bellman_ford(){
    dist.assign(N+1,INF) ;
    parent.assign(N+1,-1) ;

    dist[S] = 0 ; // S = starting node

    int cycle = 0 ;
    for(int i = 0 ; i < N ; i++){
        cycle = -1 ;

        for(Edge e : graph){
            if(dist[e.u] < INF){
                if(dist[e.u] + e.w  < dist[e.v]){
                    dist[e.v] = max(-INF , dist[e.u] + e.w ); //limiting to -INF
                    parent[e.v] = e.u ;
                    cycle = e.v ;
                }
            }
        }

        if(cycle == -1) break ;

    }

    if(cycle == -1){
        cout << "No negative cycle."<< endl ;
        if(dist[T] == INF) cout << "Impossible to reach " << S << " " << T << "." << endl;
        else {
            cout << "Cost " << S <<" To " << T  << " is "<< dist[T] <<" ." << endl ;
            path_printing(T) ;
        }
    }
    else{
        cout <<"Negative Cycle." << endl ; ;
        int y = parent[cycle] ;
        bool got = false ;

        vector<int> path ;
        for(int cur = cycle ; ; cur = parent[cur]){
            path.emplace_back(cur) ;
            if(cur == cycle && got) break ;
            if(cur == cycle) got = true ;
        }

        reverse(path.begin(),path.end()) ;
        cout << "Path : " ;
        for(auto x : path) cout << x <<" " ;
        cout << endl ;
    }

}

void solve(){
    cin >> N >> M ;
    cin >> S >> T ;

    for(int i = 0 ; i < M ; i++){
        int u , v , w ;
        cin >> u >> v >> w;

        // directed graph
        graph.emplace_back(Edge(u,v,w)) ;
    }

    Bellman_ford() ;

    
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
