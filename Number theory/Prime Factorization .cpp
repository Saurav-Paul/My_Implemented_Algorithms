/*
    Here, primelist contain all prime number 1 to N . This should be calculated using
    sieve algorithm .

    This function will print all prime factor .

*/
void factorization(int n){
    int node = n ;

    for(auto x : primelist){
        if(x*x > n) break ;
        while(n%x == 0){
            cout << x << " ";
            n /= x;
        }
    }
    if(n > 1)
        cout << n << " ";
    cout << endl ;
}
