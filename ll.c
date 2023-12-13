#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head;

void insertbegin();
void insertlast();
void insertrandom();
void deletebegin();
void deletelast();
void deleterandom();
void display();


int main()
{
    int choice=0;
    while(choice!=9)
    {
    printf("\n1.INSERT AT BEGGINING\n2.INSERT AT LAST\n3.INSERT AT RANDOM\n4.DELETE FROM THE BEGINNING\n5.DELETE FROM LAST\n6.DELETE FROM RANDOM POSITION\n7.DISPLAY\n8.EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insertbegin();
        break;
        case 2:
        insertlast();
        break;
        case 3:
        insertrandom();
        break;
        case 4:
        deletebegin();
        break;
        case 5:
        deletelast();
        break;
        case 6:
        deleterandom();
        break;
        case 7:
        display();
        break;
        case 8:
        exit(0);
        default:
        printf("INVALID CHOICE");
    }    
    }
}

void insertbegin()
{
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insertlast()
{
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE DATA:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        insertbegin();
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}

void insertrandom()
{
    int loc,i=1;
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    printf("LOCATION AT WHICH YOU WANT TO INSERT");
    scanf("%d",&loc);
    printf("ENTER THE DATA:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        insertbegin();
    }
    else
    {
        temp=head;
        while(i<loc-1)
        {
            temp=temp->next;
            i++;
            if(temp==NULL)
            {
                printf("INVALID LOCATION");
            }
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deletebegin()
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    if(head==NULL)
    {
        printf("THE LL IS EMPTY");
    }
    else
    {
        head=head->next;
        free(temp);
    }
}

void deletelast()
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    struct node * prev = (struct node*)malloc(sizeof(struct node));
    temp=head;
    if(head==NULL)
    {
        printf("THE LL IS EMPTY");
    }
    else if(head->next == NULL)
    {
        deletebegin();
        return;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}

void deleterandom()
{
    int loc,i=1;
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    struct node * prev = (struct node*)malloc(sizeof(struct node));
    printf("WHAT lOCATION DO YOU WANT TO DELETE IT FROM");
    scanf("%d",&loc);
    temp=head;
    if(head==NULL)
    {
        printf("THE LL IS EMPTY");
    }
    else if(head->next == NULL)
    {
        deletebegin();
        return;
    }
    else
    {
        temp=head;
        while(i<loc)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        free(temp);
    }
}

void display()
{
    int i=1;
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    if(head==NULL)
    {
        printf("EMPTYV LIST");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
