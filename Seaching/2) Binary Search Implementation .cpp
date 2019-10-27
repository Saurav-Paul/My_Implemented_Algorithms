            /*Saurav Paul*/
/*2) Binary Search Implementation */
//Code :
#include<stdio.h>
int ara[500];
int binsearch(int start, int stop, int num);
int main()
{
    int n,value;
    scanf("%d",&n);
    for(value=0; value<n; value++)
    {
        scanf("%d",&ara[value]);
    }
    int num;
    scanf("%d",&num);
    int position = binsearch(0,n-1,num);
    if(position==-1)
        printf("This number is not in this array .\n");
    else
        printf("%d\n",position);

}
int binsearch(int start, int stop, int num)
{
    int mid=(start+stop);
    mid/=2;
    if(num==ara[mid])
        return mid;

    else if(num>ara[stop] || num<ara[start] || mid<0)
        return -1;

    else if( num>ara[mid])
        return binsearch(mid+1,stop,num);
    else if(num<ara[mid])
        return binsearch(start,mid-1,num);
}
