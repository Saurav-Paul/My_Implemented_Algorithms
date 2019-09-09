string addString (string a, string b){
	int l1 = a.size() , l2 = b.size();
	if(l1 > l2){
		swap(a,b);
		swap(l1,l2);
	}
	string ans ="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
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
