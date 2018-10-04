#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int prime[300000],nPrime;
int mark[1000002];
void sieve(int n);

int main()
{
    int n,value;
    cout<<"Give a number where to stop : ";
    cin>>n;
    sieve(n);
    cout<<"\nAll Prime numbers are between 1 to "<<n<<" are :\t";
    for(value=0; value<nPrime; value++)
    {
        cout<<prime[value]<<"\t";
    }

    cout<<endl;
    return 0;

}

void sieve(int n)
{
    int i,j,limit=sqrt(n*1.)+2;
    prime[0]=2;
    //take 1 for not prime and 0 for prime
    mark[1]=1;
    //almost all even are,not prime
    for(i=4; i<=n; i+=2)
    {
        mark[i]=1;
    }
    //2 is prime
    mark[nPrime++]=2;
    //run loop for only odds
    for(i=3; i<=n; i+=2)
        //if not prime, no need to do multiple cutting
        if(!mark[i])
        {
            //i is prime
            prime[nPrime++]=i;

            //if we don,t do it, following
            //i*i may overflow
            if(i<=limit)
            {
                //loop though all odd multiples of i
                //greater than i*i
                for(j=i*i; j<=n; j+=i*2)
                {
                    //mark j not prime
                    mark[j]=1;
                }
            }
        }


}
