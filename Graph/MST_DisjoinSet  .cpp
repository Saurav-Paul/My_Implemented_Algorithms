
/**
 *    author        : Saurav-Paul 
 *    created       : September 19, 2020 8:53 AM
 *    Problem Name  : 1040 - Donation
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1040
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class Edge{
    public :
        int u , v, w ;

        Edge(int _u , int _v , int _w){
            u = _u , v = _v , w = _w ;
        }
};

bool operator<(Edge a , Edge b){
    return a.w > b.w ;
}

class TC{

    static const int nax = 55 ;
    int N , total = 0 , cost = 0;
    priority_queue<Edge> PQ ;

    vector<int> parent ;

    vector<bool> taken ;

    int find_parent(int node){
        if(parent[node] == node)
            return node ;
        return parent[node] = find_parent(parent[node]) ;
    }

    void MST(){

        taken.assign(N+1,false) ;
        while(!PQ.empty()){
            Edge curr = PQ.top() ;
            PQ.pop() ;

            int u_parent = find_parent(curr.u) ;
            int v_parent = find_parent(curr.v) ;

            if(u_parent != v_parent){
                cost += curr.w ;
                parent[u_parent] = v_parent ;
            }

        }

    }

    public :
    void solve(){
        scanf("%d",&N) ;

        parent.assign(N+1,0) ;
        for(int i = 1 ; i <= N ; i++){
            parent[i] = i ;
            for(int j = 1; j <= N ; j++){
                int x ;
                scanf("%d",&x) ;
                if(x){
                    total += x ;
                    PQ.push(Edge(i,j,x)) ;
                }
            }
        }

        MST() ;

        map<int,int> cnt ;

        for(int i = 1; i <= N ; i++){
            cnt[find_parent(i)] ++ ;
        }

        if((int)cnt.size() > 1){
            puts("-1") ;
        }
        else{
            printf("%d\n",total-cost) ;
        }

    }
};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d: ",i) ;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
