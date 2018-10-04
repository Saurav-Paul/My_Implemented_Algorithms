#include<stdio.h>
int ara[100];
void merge_sort(int left, int right);
void merging(int left, int mid, int right);
int main()
{
    int n;
    printf("How many number you have : ");
    scanf("%d",&n);

    printf("Enter all the number : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    merge_sort(0,n-1);
    printf("After sorting  : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",ara[i]);
    }
    return 0;
}
void merge_sort(int left, int right)
{
    int mid=left+right;
    mid/=2;
    if(right>left)
    {
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merging(left,mid,right);
    }
}
void merging(int left, int mid, int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int tempara1[n1],tempara2[n2];

//    printf("1st array : ");
    for(int i=0; i<n1; i++)
    {
        tempara1[i]=ara[left+i];
//        printf("%d ",tempara1[i]);
    }
//    printf("\n2nd array : ");
    for(int i=0; i<n2; i++)
    {
        tempara2[i]=ara[mid+1+i];
//        printf("%d ",tempara2[i]);
    }
//    printf("\n");
    int i=0,j=0,temp=left;
//    printf("\n");
    while(i<n1 && j<n2)
    {

        if(tempara1[i]<tempara2[j])
        {
            ara[temp]=tempara1[i];
            i++;
            temp++;
        }
        else{
           ara[temp]=tempara2[j];
            j++;
            temp++;
        }

    }
    while(i<n1)
    {
        ara[temp]=tempara1[i];
        i++;
        temp++;
    }
    while(j<n2)
    {
        ara[temp]=tempara2[j];
        j++;
        temp++;

    }
   /*
    printf("after merging array : ");
    for(int i=left;i<=right;i++){
        printf("%d ", ara[i]);
    }
    printf("\n");
    */
}
