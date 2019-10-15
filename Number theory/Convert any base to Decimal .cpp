				/*Saurav Paul*/
auto using ll = long long int ;
ll val(char c)
{
    if (c >= '0' && c <= '9')
        return (ll)c - '0';
    else
        return (ll)c - 'A' + 10;
}

ll toDeci( ll base ,string str)
{
    ll len = str.size();
    ll power = 1;     ll num = 0;

    for (ll i = len - 1; i >= 0; i--)
    {
        ll value = val(str[i]) ;

        if (value >= base)
        {
           cout << "Invalid" << endl ;
           return -1;
        }

        num += (power * base) ;
        power *= base ;
    }

    return num;
}
