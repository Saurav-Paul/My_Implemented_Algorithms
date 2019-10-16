/*                  Saurav Paul
  This Function can convert decimal number to any base number ...
 */
void DeciToAnyBase(ll number , ll base){

    string ans = "";
    while(number != 0){
        ll reminder = number%base ;
        number /= base ;
        char c ;
        if(reminder < 10){
            // adding '0' to convert it into char...
            c =  reminder + 48;
        }
        else{
            c = reminder + 'A' - 10 ;
        }
        ans += c ;

    }
    reverse(ans.begin() , ans.end() );
    cout << ans << endl ;

}
