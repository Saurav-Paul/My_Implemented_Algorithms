/*linear searching */
//Code :
#include<stdio.h>
int main(){
int n;

scanf("%d",&n);
int ara[n],i;
for(i=0;i<n;i++){

    scanf("%d",&ara[i]);
}
int m;

scanf("%d",&m);
int t=10;
for(i=0;i<n;i++){
 if(ara[i]==m){
        t=0;
 printf("%d\n",i);
 break;
 }
}
return 0;
}
