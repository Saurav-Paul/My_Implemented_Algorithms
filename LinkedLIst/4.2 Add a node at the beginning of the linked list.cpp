/*4.2 Add a node at the beginning of the linked list */
//Code :
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void begining(int value);
void display();
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
        begining(num);
    }
    printf("Node added the beginning of the linked list  : ");
    display();
    return 0;
}
void begining(int value)
{

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }

    else
    {

        temp->next=head;
        head=temp;

    }
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
