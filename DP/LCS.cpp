				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using vec = vector<int> ;

int main()
{
	ios_base::sync_with_stdio(false) ;
	
	string a , b; cin >> a >> b;
	int asz = a.size() , bsz = b.size() ;
	vector< vec > dp(asz + 1 , vec (bsz + 1 ,0 ) ) ;
	
	for(int i =1 ; i <= asz ; i++){
		for(int j = 1; j <= bsz ; j++){
			if(a[i-1] == b[j-1] ){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1] );
			}
		}
	}
	
	int mxlen = dp[asz][bsz] ;
	
	string ans = "";
	int i = asz, j = bsz ;
	while(mxlen){
		if(a[i-1] == b[j-1]){
			ans += a[i-1] ;
			i--, j--;
			mxlen --;
		}
		else if(dp[i][j] == dp[i-1][j]){
			i--;
		}
		else{
			j--;
		}
	}
	
	reverse(ans.begin() , ans.end() );
	cout << ans << endl;
	
    return 0;
}
