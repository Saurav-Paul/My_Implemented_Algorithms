/*       Saurav Paul
  Here one is string and second number is long long int , though it can be easily converted to multiply both string number */
string addStringModified (string a, string b){
	reverse(a.begin(),a.end());
	int l1 = a.size() , l2 = b.size();
	if(l1 > l2){
		swap(a,b);
		swap(l1,l2);
	}
	string ans ="";

	bool carry = false;
	
	for(int i = 0 ;i < l1 ; i++){
		int temp = (a[i]-'0') + (b[i]-'0') + (carry);
		carry = false;
		if(temp > 9){
			carry = true;
			temp = temp-10;
		}
		ans += (temp+'0');
	}
	for(int i = l1 ; i < l2 ; i++){
		int temp = (b[i]-'0') + (carry);
		carry = false;
		if(temp > 9){
			carry = true;
			temp = temp-10;
		}
		ans += (temp+'0');
	}
	if(carry) ans += '1';
	reverse(ans.begin(),ans.end());
	
	return ans;
}

string multiplication(string s, ll n ){
	
	reverse(s.begin() , s.end() ) ;

	string ans = "0";
	int koy_number = 0 ;
	while( n!= 0 ){
		int num = n%10 ;
		n /= 10 ;
		
		int carry = 0 ;
		
		string temp = "";
		for(auto x : s ) {
			int y = carry + (x - '0' ) * num;
			carry = 0;
			if( y > 9 ){
				carry = y / 10 ;
				y %= 10;
			}
			
			temp += char( y + '0' ) ;
		}
		if(carry) temp += char(carry + '0' ) ;
		
		string zero = "";
		for(int i = 0 ; i < koy_number ; i++) {
			zero += '0' ;
		}
		temp = zero + temp ;
		ans = addStringModified(ans,temp) ;
		koy_number ++;
		
	}

	return ans ; 
}
