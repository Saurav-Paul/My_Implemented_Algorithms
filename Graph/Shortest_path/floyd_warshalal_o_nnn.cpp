
/**
 *    author        : Saurav Paul 
 *    created       : August 26, 2020 11:25 AM
 *    Problem Name  : All pairs shortest path cost - Floyd Warshall 
 *    Complexity    : O(N^3) 
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

const int INF = 1e9 + 90 ;
const int nax = 100+10 ;
int dist[nax][nax] ;
int N, M ; //N = node , M = edge

void floyd_Warshall(){
    // 1....N
    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]) ;
                }
            }
        }
    }
    // printing shortest distance
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cout << i <<" to " << j << " minimum cost is " << dist[i][j] << endl ;
        }
    }
}

void clear(){
    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j <= N ; j++){
            if(i == j) dist[i][j] = 0 ;
            else dist[i][j] = INF ;
        }
    }
}
void solve(){
    cin >> N >> M ;

    clear() ;
    for(int i = 0 ; i < N ; i++){
        int u , v , w;
        cin >> u >> v >> w ;
        dist[u][v] = w ; // directed graph
    }

    floyd_Warshall() ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    /* cin >> testcases ; */
    for(int i = 1 ; i <= testcases ; i ++){
        solve();
    }

    return 0 ;
}
