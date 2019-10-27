            /*Saurav Paul*/
/* Here primelist is set of all primenumber and it should be calculated using
   sieve algorithm. This function calculate number of divisor using factorization.
   
   We know  , number x = 2^a1 * 3^a2 * 5*a3 ..... ( power of all Prime number) 
   from there we can calculate NOD = (a1+1) * (a2+1) * (a3+1) .....
*/

long long number_of_divisor(long long n){
    long long cnt = 1;
    for(auto x : primelist){
        if(x*x > n)
            break ;

        long long temp = 1;
        while(n%x==0){
            temp ++;
            n/= x ;
        }
        cnt *= temp;
    }
    if(n > 1) cnt *= 2;
    return cnt ;
}
