#include<bits/stdc++.h>
using namespace std; 

void Rabin_Karp(string &s,string &pattern){
	
	int plen = (int)pattern.size();
	int slen = (int)s.size();
	vector<int> match;
	long long int hash = 0,patternHash=0 , prime = 3;
	// finding patternhash and the first part hash...
	for(int i=0 ; i < plen ; i++){
		hash += s[i] * pow(prime,i);
		patternHash += pattern[i] * pow(prime,i);
		
	}
	// checking if first part is same...
	if(patternHash == hash)
		match.emplace_back(0);
	for(int i = plen ; i < slen ; i++){
		hash -= s[i-plen];
		hash /=prime;
		hash += s[i] * pow(prime,plen-1);
		//cerr << patternHash <<" "<<hash << endl;
		if(patternHash == hash)
		{
			bool flag = true;
			for(int j = i-plen+1,k=0 ; j <= i ; j++,k++){
				if(s[j] != pattern[k]){
					flag = false;
					break ;
				}
			}
			if(flag)
				match.emplace_back(i-plen+1);
		}
	}
	
	// printing all matched starting points..
	printf("Total matched : %d\n",(int)match.size());
	for(auto x : match)
		printf("%d ",x);
		
	return ;
}

int main(){
	
	string s,pattern;
	cin >> s >> pattern;
	Rabin_Karp(s,pattern);
	
	return 0;
}
