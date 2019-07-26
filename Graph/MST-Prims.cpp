#include<bits/stdc++.h>
using namespace std;

class obj{
	public :
		int u , v;
		double  prop;
		
		obj(int a , int b, double x){
			u = a, v = b;
			prop = x ;
		}
};


class Compare{
	public :
		bool operator ()(obj &a , obj &b){
			return a.prop > b.prop;
		}
};

inline double cal( pair<double , double> &x, pair<double, double > &y){
	
	return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)
					* (x.second-y.second));		
	
}

void solve(){
	
	priority_queue<obj , vector<obj >, Compare > pq;
	int n; 
	scanf("%d",&n);
	vector< pair<double, double> > v(n);
	for(int i = 0 ; i < n; i++){
		double x , y;
		scanf("%lf%lf",&x,&y);
		v[i] = {x,y} ;
	}

	for(int i = 1 ; i < n ; i++){
		obj temp(0,i,cal(v[0],v[i]));
		pq.push(temp);
	}
	
	bool isvisited[n+5];
	memset(isvisited,false,sizeof isvisited);
	isvisited[0] = true;
	double sum  = 0.0;
	
	
	while(!pq.empty()){
		
		obj temp = pq.top();
		pq.pop();
		if(isvisited[temp.v])
			continue ;
		sum += temp.prop;
		isvisited[temp.v] = true;
		for(int i = 0 ; i < n; i++)
			if(i != temp.v){
				obj x(temp.v,i, cal(v[temp.v] , v[i]));
				pq.push(x);
			}
		
	}
	printf("%.2lf\n",sum);
}

int main(){
	
	int t ;
	scanf("%d",&t);
	while(t--)
		solve(),printf("%s",(t?"\n":""));
	
	return 0;
}
