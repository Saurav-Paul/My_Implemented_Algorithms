/*4.7 Search for a node */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void input (int value);
void display();
void searchnode(int n);
struct node* head;
int main()
{
    head=NULL;
    int n,searchnum;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++){
        int num;
        printf("Enter the number : ");
        scanf("%d",&num);
        input(num);
    }
    printf("Enter the node to search :");
    scanf("%d",&searchnum);
    searchnode(searchnum);
}
void input (int value)
{
    struct node* temp=(struct node*) malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL)
    {
        head=temp;

    }
    else
    {
        struct node* test;
        test=head;
        while(test->next!=NULL)
        {
            test=test->next;
        }
        test->next=temp;

    }
    temp->next=NULL;

}

void display()
{
    struct node* info;
    info=head;
    while(info!=NULL)
    {
        printf("%d ",info->data);
        info=info->next;
    }
    printf("\n");
}
void searchnode(int n)
{
    struct node* temp;
    temp=head;
    int t=0;
    n--;
    while(temp!=NULL && n--)
    {
        temp=temp->next;
        t=1;
    }
    if(t){
        printf("The value of searched node is : %d\n",temp->data);
    }
    else {
       printf("Node doesn't exit.");
   }

}
