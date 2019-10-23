                    /*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
class ChineseReminderTheorem{
	
	public :
	ChineseReminderTheorem(vector<int> &num,vector<int> &rem){
			/*
			 * Let us take below example to understand the solution
			   num[] = {3, 4, 5}, rem[] = {2, 3, 1}
			   mul  = 60  // product of all num
			   pp[]  = {20, 15, 12}
			   inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
									// (12*3)%5 = 1

			   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] + 
					rem[2]*pp[2]*inv[2]) % mul
				 = (2*20*2 + 3*15*3 + 1*12*3) % 60
				 = (40 + 135 + 36) % 60
				 = 11
				 * 
			 */

			int mul=1;
			for(auto x : num)
				mul *= x;

			// now need pp[i]...p[i]=mul/num[i]...
			vector <int > pp;
			for(auto x : num){
				pp.emplace_back(mul/x);
			}
			// last thing needed is Modular Multicative inverse
			// of pp[i] with respect to num[i]...
			vector <int > inv;
			int n = num.size();
			for(int i = 0 ; i< n; i++){
				int temp = modInverse(mul/num[i],num[i]);
				inv.emplace_back(temp);
			}

			int ans = 0;
			for(int i = 0 ; i < n; i++){
				ans += (rem[i]*pp[i]*inv[i])%mul;
			}
			printf("%d\n",(ans)%mul);
	}
	int modInverse(int a, int m){ 
			int m0 = m; 
			int y = 0, x = 1; 
		  
			if (m == 1) 
			  return 0; 
		  
			while (a > 1) 
			{ 
				// q is quotient 
				int q = a / m; 
				int t = m; 
		  
				// m is remainder now, process same as 
				// Euclid's algo 
				m = a % m, a = t; 
				t = y; 
		  
				// Update y and x 
				y = x - q * y; 
				x = t; 
			} 
		  
			// Make x positive 
			if (x < 0) 
			   x += m0; 
		  
			return x; 
	}
};

int main(){
	// given number...
	vector <int > num({3,4,5});
	// given reminder...
	vector <int > rem({2,3,1});
	
	ChineseReminderTheorem obj(num,rem);
	
	return 0;
}
