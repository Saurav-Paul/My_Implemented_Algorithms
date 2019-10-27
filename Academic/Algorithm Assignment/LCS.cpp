#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string a, b;
	cin>>a>>b;
	int asz=a.size();
	int bsz=b.size();
	int dp[asz+1][bsz+1];
	for(int i=0; i<=asz ; i++){
		for(int j=0; j<=bsz ; j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=1; i<=asz ; i++){
		for(int j=1; j<=bsz ; j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1 ;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<"Length of the longest common subsequence : "<<dp[asz][bsz]<<endl;
	string ans="";
	int i=asz,j=bsz;
	while(i>0 && j>0){
		
		if(dp[i][j]==0)
			break ;
		if(dp[i][j]==dp[i-1][j]){
			i--;
		}else if(dp[i][j]==dp[i][j-1]){
			j--;
		}else{
			ans.push_back(a[i-1]);
			i--;
			j--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<"And the longest common subsequence is : ";
	cout<<ans<<endl;
	return 0;
}
