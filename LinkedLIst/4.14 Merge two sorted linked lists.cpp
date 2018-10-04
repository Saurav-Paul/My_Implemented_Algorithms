/*4.14 Merge two sorted linked lists  */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void input (int value);
void display();
void mergeTwoLinkList(struct node* ,struct node*);
struct node* head;
struct node*head1,*head2;
int main()
{
    head=NULL;
    int n,searchnum;
    printf("First Linked List :\nEnter the value of n : ");
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++){
        int num;
        printf("Enter the number : ");
        scanf("%d",&num);
        input(num);
    }
    printf("First linked list : ");
    display();
    head1=head;
    head=NULL;
    printf("Second Linked List :\nEnter the value of n : ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        int num;
        printf("Enter the number : ");
        scanf("%d",&num);
        input(num);
    }
    printf("Second linked list : ");
    display();
    head2=head;
    head=NULL;
    printf("After merging both linked list : ");
    mergeTwoLinkList(head1,head2) ;
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
void mergeTwoLinkList(struct node* h1, struct node* h2)
{
    struct node* temp;
    temp=h1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=h2;
    head=h1;
}
