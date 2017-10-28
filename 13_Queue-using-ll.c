#include<stdio.h>
#define MS 5
int e,c=0;
void insert(int);
int delete();
int peek();
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp,*ptr;
struct node *newnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
};
void deletenode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}
int main()
{
    int ch;

    do
    {
        printf("\n----------Linear Queue operations-----------");
        printf("\n 1. INSERT ");
        printf("\n 2. DELETE ");
        printf("\n 3. PEEK FRONT ");
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
            if(front==NULL)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n deleted Element is : %d ",deleteq());
            break;

        case 3:
            printf("\nFront element is : %d ",peek());

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

void insert(int e)
{
    temp=newnode();
    temp->data=e;
    temp->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    c++;


}

int deleteq()
{
    if(front==NULL&&rear==NULL)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    e=front->data;

    if(front==rear)
    {
        front=rear=NULL;
    }
    else
        front=front->next;

    return e;
}



void display()
{
    int i;

    if(front==NULL&&rear==NULL)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    ptr=front;
    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
}
int peek()
{
    if(front==NULL)
    {
        printf("**EMPTY STACK**");
        return 0;
    }

    int e=front->data;
    return e;
}
