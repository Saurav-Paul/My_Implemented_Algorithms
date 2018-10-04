/*4.6 Insert a new node before a particular node    */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void input (int value);
void display();
void particular_input(int value,int n);
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
    printf("Node added the end of the linked list  : ");
    display();
     int m,num;
    printf("Write the number (m),where you want to add new node (m<n) : ");
    scanf("%d",&m);
    printf("Enter the number : ");
    scanf("%d",&num);
    particular_input(m,num);
    display();

    return 0;
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
void particular_input(int value,int n)
{

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    struct node* test=(struct node*)malloc(sizeof(struct node));
    test=head;
    value-=2;
    while(value--)
    {
        test=test->next;
    }
    temp->next=test->next ;
    test->next=temp;
}
