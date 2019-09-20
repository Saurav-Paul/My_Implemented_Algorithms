#include<bits/stdc++.h>
using namespace std;

double sqrt_func(double num){
	double low = 0.0 , high = num;
	while(high-low > .001 ){
		double mid = (high + low ) / 2.0;
		if(mid*mid > num) high = mid;
		else low = mid;
	}
	return low;
}

int main(){
	double num ;
	cin >> num;
	double ans = (double) sqrt_func(num)  ;
	printf("%.10lf\n",ans);
	return 0;
}
