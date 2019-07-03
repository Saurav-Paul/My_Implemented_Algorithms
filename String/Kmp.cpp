#include<bits/stdc++.h>
using namespace std;

class kmp{
	public :
	void find_kmp(string &s, string &pattern){
		int sz = (int)pattern.size();
		vector<int> suffix(sz), matched;
		build_suffix_array(suffix,pattern,sz);
		
		int n = (int) s.size();
		for(int i = 0,j=0 ; j < n; ){
			if(s[j]==pattern[i]){
				i++;
				j++;
				if(i==sz){
					matched.emplace_back(j-sz);
					if(i)
						i = suffix[i-1];
				}
			}
			else{
				if(i){
					i = suffix[i-1];
				}
				else{
					j++;
				}
			}
		}
		printf("Total matched : %d\n",(int)matched.size());
		
		for(int x : matched)
			printf("%d ",x);
		puts("");
		
	}
	
	private :
	void build_suffix_array(vector<int> &suffix,string & s,int sz){
		/** a b c d a b c y
			0 0 0 0 1 2 3 0
		**/
		for(int i = 0 , j = 1 ; j < sz ; ){
			
			if(s[i]==s[j]){
				suffix[j] = i+1;
				i++ , j++;
			}
			else{
				if(i){
					i = suffix[i-1] ;
				}
				else{
					suffix[j] = 0;
					j++;
				}
			}
		}
		
	}
};


int main(){
	string s, pattern;
	cin >> s >> pattern;
	kmp obj;
	obj.find_kmp(s,pattern);
	
	return 0;
}
