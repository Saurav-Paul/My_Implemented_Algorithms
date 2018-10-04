/*4.9 Reverse linked list  */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void input (int value);
void display();
void reversenode(int n);
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
    printf("Given linked list : ");
    display();
    printf("\nReversed linked list :");
    reversenode(n);
    display();

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
void reversenode(int n)
{


    struct node* temp=head;
    struct node* test;
    int x=0;
    for(temp=head; temp!=NULL; temp=temp->next)
    {
        for(test=temp->next,x=0; test!=NULL && x<n; test=test->next,x++)
        {

            int t=temp->data;
            temp->data=test->data;
            test->data=t;

        }
        n--;

    }

}
