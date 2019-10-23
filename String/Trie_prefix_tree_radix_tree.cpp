                    /*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
class node{
	public :
		bool endmark;
		node *next[27];
	
	node(){
		endmark = false;
		for(int i =0 ; i < 26 ; i++)
			next[i] = NULL;
	}
} *root;

void insert(string &s){
	int sz= (int)s.size();
	node * curr = root;
	
	for(int i = 0 ; i < sz; i++){
		int id = (int) s[i]-'a';
		if(curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
	}
	curr -> endmark = true ;
}

bool search(string &s){
	int sz = (int)s.size();
	node * curr = root;
	for(int i =0 ; i< sz ; i++){
		int id = (int) s[i]-'a';
		if(curr->next[id] == NULL)
			return false;
		curr = curr->next[id];
	}
	return curr->endmark;
}
void del(node *curr){
	
	for(int i = 0 ; i < 26 ; i++){
		if(curr->next[i])
			del(curr->next[i]);
	}
	delete (curr);
}
int main(){
	
	ios_base::sync_with_stdio(false);
	root = new node() ;
	cout << "How much word do you want to insert in your dictionary? : ";
	int n ; cin >> n;
	cout <<"Enter "<<n<<" word : "<<endl;
	while(n--){
		string s; cin >> s;
		insert(s);
	}
	cout<<"Enter the number of your query :";
	cin >> n;
	cout<<"Enter the word to serach : "<<endl;
	while(n--){
		string s; cin >> s;
		cout<< (search(s)? "Found!" : "Not-found!!!") <<endl;
	}
	del(root);
	return 0;
}
