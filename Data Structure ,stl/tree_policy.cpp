 #include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    Map dynamic_set;
    int query,temp;
    cin>>query;
    while(query--)
    {

        cin>>c;
        if(c=='I')
        {
            cin>>temp;
            dynamic_set.insert(temp);
            continue;
        }
        if(c=='K')
        {
            cin>>temp;
            if(temp>dynamic_set.size())
                printf("invalid\n");

            else
                printf("%d\n",*dynamic_set.find_by_order(temp-1));
            continue;
        }
        if(c=='C')
        {
            cin>>temp;
            printf("%d\n",dynamic_set.order_of_key(temp));
            continue;
        }
        if(c=='D')
        {
            cin>>temp;
            dynamic_set.erase(temp);

        }



    }


    return 0;
}
