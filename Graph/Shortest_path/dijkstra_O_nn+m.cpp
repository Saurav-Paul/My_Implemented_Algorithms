
/**
 *    author        : Saurav Paul 
 *    created       : August 25, 2020 11:40 AM
 *    Problem Name  : Basic Dijkstra Algorithm Implementation
 *    Complexity    : O(n^2 + m)
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 90 ;
int N , M , S , T ;

vector<vector<pair<int,int>>> graph ;
vector<int> d , p ;

void path_print() {

    vector<int> path;

    for (int v = T; v != S; v = p[v])
        path.push_back(v);
    path.push_back(S);

    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << " " ;
    cout << "\n" ;
}

void dijkstra() {

    // 0 based graph implementation - warning
    int n = N;
    d.assign(n+1, INF);
    p.assign(n+1, -1);
    vector<bool> u(n, false);

    d[S] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    if(d[T] == INF){
        cout << -1 << endl ;
    }
    else{
        cout << d[T] << "\n" ;
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

    dijkstra() ;
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
