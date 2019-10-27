
#include<bits/stdc++.h>
using namespace std;


const int INF = 1e9 + 90;
struct details{
	int processno, burst , arrival ,have ,priority;
	
};

struct all_prop{
	int at , bt, tat, wt, rt ,ct ;
};

int main(){
	cout << "\t\tPriority algorithm"<<endl<<endl;
	int noProcess;
	cout << "Enter the number of process : ";
	cin >> noProcess ;
	cout << endl ;
	vector<details> process(noProcess);
	for(int i = 0 ; i < noProcess ; i++){
		cout <<"Enter the priority , arrival time and brust time of process no "<<i+1 << ": " ;
		cin >>process[i].priority >> process[i].arrival >> process[i].burst ;
		process[i].processno = i ;
		process[i].have = process[i].burst ;
	}
	sort(process.begin() , process.end() , [](details &x ,
								details &y ) {
								if(x.arrival == y.arrival) 
									return x.priority >y.priority ;
								return x.arrival < y.arrival ;
							});
	
	
	
	
	vector<all_prop> ans(noProcess) ;
	
	int cnt = 0 ;
	int curr_time = 0 ;
	vector<int> firstResponse(noProcess,-1);
	while( cnt< noProcess ){
		int mx = -1 , select = -1 ;
		for(int i = 0 ; i < noProcess ; i++){
			if(process[i].arrival <= curr_time && process[i].have> 0
					&& process[i].priority > mx){
				mx = process[i].priority ;
				select = i ;
				
			}
			
		}
		if(select != -1){
			if(firstResponse[select] == -1)
				firstResponse[select] = curr_time - process[select].arrival;
			process[select].have --;
			if(process[select].have == 0){
				cnt ++;
				all_prop x ;
				x.at = process[select].arrival;
				x.bt = process[select].burst;
				x.ct = curr_time + 1;
				x.tat = x.ct - x.at ;
				x.wt = x.tat - x.bt;
				x.rt = firstResponse[select] ;
				
				ans[process[select].processno] = x ;
			}
			
		}
		curr_time ++;
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
