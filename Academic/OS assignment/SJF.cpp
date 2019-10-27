#include<bits/stdc++.h>
using namespace std ;

const int INF = 1e9 + 90;
struct details{
	int processno, burst , arrival ;
	
};

struct all_prop{
	int at , bt, tat, wt, rt ,ct ;
};

int main(){
	cout << "\t\tSJF algorithm"<<endl<<endl;
	int noProcess;
	cout << "Enter the number of process : ";
	cin >> noProcess ;
	cout << endl ;
	vector<details> process(noProcess);
	for(int i = 0 ; i < noProcess ; i++){
		cout <<"Enter the arrival time and brust time of process no "<<i+1 << ": " ;
		cin >> process[i].arrival >> process[i].burst ;
		process[i].processno = i ;
	}
	sort(process.begin() , process.end() , [](details &x ,
								details &y ) {
								if(x.arrival == y.arrival) 
									return x.burst < y.burst ;
								return x.arrival < y.arrival ;
							});
	
	
	cout << endl << endl ;
	int curr_time = 0;
	vector<all_prop> ans(noProcess+1);
	vector<bool> done(noProcess,false) ;
	for(int i = 0 ; i < noProcess ; i++){
		
		int select = -1 ;
		int mn = INF;
		bool ok = true ;
		while(ok){
			for(int j = 0; j < noProcess ; j++){
				if(done[j] == false){
					if(process[j].burst < mn && curr_time >= process[j].arrival){
						select = j ;
						mn = process[j].burst ;
						ok = false;
					}
					
				}
			}
			if(ok) curr_time ++ ;
		}
		if(select == -1 ) assert(false) ;
		done[select] = true ;
		all_prop x ;
		x.at = process[select].arrival ;
		curr_time = max(curr_time , x.at) ;
		x.bt	  = process[select].burst ;
		x.ct 	  =	curr_time + x.bt ;
		x.tat	  = x.ct - x.at ;
		x.wt	  = x.tat - x.bt ;
		x.rt 	  = x.wt ;
		ans[process[select].processno] = x;
		curr_time = x.ct ;
	}
	
	
	double atat=0.0, awt=0.0;
	
	cout<<"Process\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T.\tR.T.\n";
	for(int i = 0 ; i < noProcess ; i++){
		all_prop x = ans[i] ;
		printf("#%d\t",i+1);
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",x.at,x.bt,x.ct,x.tat,x.wt,x.rt);
		atat+=x.ct;
		awt += x.wt;
	}
	
	printf("\nAverage TAT : %g\n",(atat/noProcess));
	printf("Average Wating Time : %g\n",(awt/noProcess));
	
	return 0 ;
}
