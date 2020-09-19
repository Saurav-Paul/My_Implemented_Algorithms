
/**
 *    author        : Saurav-Paul 
 *    created       : September 19, 2020 8:48 PM
 *    Problem Name  : 1400 - Employment
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1400
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    int N ;

    vector<vector<int>> boy, girl ;

    // Stable Marriage Algorithm

    bool woman_want_to_change(int woman , int curr , int new_man){
        for(int i = 1  ; i <= N ; i++){
            int choice = girl[woman][i] ;
            if(choice == new_man) return true;
            if(choice == curr) return false;
        }
        assert(false) ;
        return false ;
    }

    void stable_marriage(){

        int Not_married = N ;

        vector<bool> married_man(N+1,false) ;
        vector<int> wparter(N+1,-1) ;

        while(Not_married){

            int man = -1 ;
            for(man = 1; man <= N ; man++){
                if(married_man[man] == false) break ;
            }

            for(int i = 1 ; i <= N && married_man[man]==false ; i++){

                int curr= boy[man][i] ;

                if(wparter[curr-N] == -1){
                    wparter[curr-N] = man ;
                    married_man[man] = true ;
                    Not_married -- ;
                }
                else{
                    int curr_married_to = wparter[curr-N] ;

                    if(woman_want_to_change(curr-N, curr_married_to , man)){
                        wparter[curr-N] = man ;
                        married_man[man] = true ;
                        married_man[curr_married_to] = false ;
                    }
                }

            }

        }

        for(int i = 1 ; i <= N ; i++){
            cout << "(" <<wparter[i] << " " << i+N << ")" ;
            if(i < N) cout << " " ;
        }
        cout << endl ;

    }

    // Stable Marriage Algorithm End

    public :
    void solve(){
        cin >> N ;

        boy.assign(N+1,vector<int>()) ;
        girl.assign(N+1,vector<int>()) ;

        for(int i = 1 ; i <= 2 ; i++){
            for(int j = 1 ; j <= N ; j++){
                vector<int> temp(N+1);
                for(int k = 1 ; k <= N ; k++){
                    cin >> temp[k] ;
                }
                if(i&1) boy[j] = temp ;
                else girl[j] = temp ;
            }
        }

        stable_marriage() ;

    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        cout << "Case " << i << ": " ;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
