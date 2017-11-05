#include<stdio.h>
#include<stdlib.h>
#define MS 5
int c;
void insert(int);
int deleteq();
int peek();
struct node
{
    int data;
    struct node *next;
};
struct node *f=NULL,*r=NULL,*ptr,*temp;
struct node *newnode()
{
    struct node *node =(struct node *)malloc(sizeof(struct node));
    return node;
};
void delnode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}
void insert(int e)
{
    temp=newnode();
    temp->data=e;
    temp->next=NULL;
    if(f==NULL)
    {
        f=r=temp;
    }
    else
    {
        r->next=temp;
        r=temp;
    }
    c++;
}
int deleteq()
{
    int e;
    e=f->data;

    if(f==r)
    {
        f=r=NULL;
    }
    else
    {
       f=f->next;
    }

    return e;

}
int peek()
{
    int e;
    e=f->data;
    return e;
}
void display()
{
    ptr=f;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

}
int main()
{
    int ch,e;
    c=0;

    do
    {
        printf("\n----------Stack operations-----------");
        printf("\n 1. INSERT ");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK ");
        printf("\n 4. DISPLAY ");
        printf("\n 5. EXIT ");
        printf("\n---------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(c==MS)
            {
                printf("**OVERFLOW**");
                break;
            }
            printf("\n Enter Element to insert : ");
            scanf("%d",&e);
            insert(e);
            break;

        case 2:
            if(f==NULL)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n Deleted Element is : %d ",deleteq());
            break;

        case 3:
            if(f==NULL)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n frontmost Element is : %d ",peek());
            break;

        case 4:
            display();
            break;

        case 5:
            printf("\n Exiting......");
            break;
        }
    }
    while(ch!=5);
}

