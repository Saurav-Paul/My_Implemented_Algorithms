/*4.8 Sort a linked list using bubble sort  */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void input (int value);
void display();
void sortnode();
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
    printf("\nSorted linked list :");
    sortnode();
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
void sortnode()
{
    struct node* temp=head;
    struct node* test;
    for(temp=head; temp!=NULL; temp=temp->next)
    {
        for(test=temp->next; test!=NULL; test=test->next)
        {
            if(temp->data>test->data)
            {
                int t=temp->data;
                temp->data=test->data;
                test->data=t;
            }
        }

    }
}
