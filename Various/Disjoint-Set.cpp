				/*Saurav Paul*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vec;;

int find_parent(vec & parrent,int x){
	
	if(parrent[x]==x)
		return x;
	return parrent[x] = find_parent(parrent,parrent[x]);
}

void solve(){
	string s;
	vector<string> v;
	set < int > myset;
	getline(cin,s);
	int n = s[0]-'A';
	vector <int > parrent(n+1);
	
	for(int i = 0 ; i <= n ; i++)
		parrent[i] = i;
	
	while(getline(cin,s) and s != ""){
		v.emplace_back(s);
		int sz = (int) s.size();
		for(int i = 1 ; i < sz ; i++){
			int s1 = find_parent(parrent,s[i-1]-'A');
			int s2 = find_parent(parrent,s[i]-'A');
			if(s1 != s2)
				parrent[s1] = s2;
		}
	}
	
	for (int i =0 ; i <= n; i++)
		myset.insert(find_parent(parrent,parrent[i]));
	
	cout << (int)myset.size() << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int testcase;
	cin >> testcase;
	string s;
	getline(cin,s);
	getline(cin,s);
	while(testcase--)
		solve(),cout<<(testcase?"\n":"");

    return 0;
}
