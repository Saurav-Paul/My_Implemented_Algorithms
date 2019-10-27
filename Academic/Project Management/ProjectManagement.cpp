#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3;

class Activity{
	public :
		int est , eft , lst , lft, tf , ff;
		int duration , id ,pred;

	Activity(){
		est = eft = lst = lft = tf = ff = 0;
		duration = id =pred= 0;
	}
	void insert(int a, int d , int c){
		id = a;
		pred = c;
		duration = d;
		cal();
		lst  = lft = 1e9+90;
	}
	void cal(){
		eft = est + duration ;
	}
	void cal2(){
		lst = lft - duration ;
		tf = abs(est - lst) ;
		ff = abs(eft - lft) ;
	}
	void update(int x){
		if(x > est){
			est = x;
			eft = est + duration ;
		}
	}
	void update2(int x){
		if( x < lft){
			lft = x ;
			lst = lft - duration ;
		}
	}
	void print(){
		cout <<"\t";
		cout <<est <<" - " << eft <<" - " << lst << " - " << lft
			<<" - "<<tf<<" - "<<ff << " - "<<duration<<endl;
	}
	void last(){
		lst = est ;
		lft = eft ;
		ff = tf = 0;
	}
};

class ProjectManagement{
	public :

		int totalActivity , assign=1 ;
		Activity activites[nax];
		map < string , int > code;
		map < int , string > name ;
		vector <int > start;
		vector <int > last;
		vector< int > graph[nax];
		vector< int > backward[nax];
		vector <int > critical_path;

	void input(){
		code["none"] = 0;
		code["None"] = 0;
		code["NONE"] = 0;
		cout << "Input total number of your activity : ";
		cin >> totalActivity;
		bool istaken[totalActivity+10] = {};
		cout << "Enter all data below ->\n";
		cout << "\n\tActivity| Duration| Predecessor\n";
		cout << "\t--------- ---------  -----------\n";

		for(int i = 0 ; i < totalActivity ; i++){
			cout << "\t#"<<i+1<<". ";
			string s, t;
			int d ;
			cin >> s;
			cin >> d ;

			char c;
			do{
			cin >> t;
			Activity x;
			if(code.find(s)==code.end())
				code[s] = assign++;
			if(code.find(t) == code.end())
				code[t] = assign++;

			int a= code[s] , b =code[t];
			name[a] = s , name[b] = t;

			if(t=="none" || t=="None" || t=="NONE"){
				if(istaken[a]==false){
					start.emplace_back(a);
					istaken[a]=true;
				}
			}

			else
				graph[b].emplace_back(a),backward[a].emplace_back(b);

			x.insert(a,d,b);
			activites[a]= x;
		}while(cin >> c and c == ',');

		}

	}
	void processing(){
		queue < int > Q;
		for(auto x : start){
			Q.push(x);

		}

		while(!Q.empty()){

			int top = Q.front();
			Q.pop();

			Activity &x = activites[top] ;
			x.cal();
			for(auto i : graph[x.id]){

				Activity &y = activites[i];
				Q.push(i);
				y.update(x.eft);

			}
		}

		for(int i = 1 ; i < assign ; i++)
			if(graph[i].size()==0){
				Q.push(i);
				activites[i].last();
			}
		bool rem[assign+10] = {};
		while(!Q.empty()){

			int top = Q.front();
			Q.pop();

			Activity &x = activites[top] ;
			x.cal2();
			if(x.ff==0 and x.tf==0){
				if(rem[top]==false)
					critical_path.emplace_back(top);
				rem[top] = true;
			}
			for(auto i : backward[x.id]){

				Activity &y = activites[i];
				Q.push(i);
				y.update2(x.lst);

			}
		}


	}
	void printActivityTable(){

		int mx = 0;
		cout << "\n\n\t\t---Activity Table---";
		cout <<"\n\tName=   EST-EFT-LST-LFT- TF- FF-Duration\n";
		for(int i = 1 ; i < assign ; i++){

			Activity x = activites[i];
			cout << "\t#"<<i<<". "<<name[x.id]<<"=";
			x.print();
			mx = max(mx,x.eft);
		}
		cout<<"\n\tMaximum Time Needed = "<< mx << endl;
		reverse(critical_path.begin(),critical_path.end());
		cout << "\n\tTotal Critical Activity = "<<(int)critical_path.size() << endl;

		cout <<"\n\n\tCritical path  ";
		for(auto i : critical_path)
			cout<<"- > "<<name[i];
		cout<< endl;

	}

};

int main(){

	ios_base::sync_with_stdio(false);
	ProjectManagement work;

	work.input();
	work.processing();
	work.printActivityTable();


	return 0;
}
