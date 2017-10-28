#include<stdio.h>
#define MS 5
int front=-1,rear=-1,e;
void insert(int);
int delete();
int peek();
void display();
int c_queue[MS];

int main()
{
    int ch;

    do
    {
        printf("\n----------Circular Queue operations-----------");
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
            if(front==(rear+1)%MS)
            {
                printf("**OVERFLOW**");
                break;
            }
            printf("\n Enter Element to insert : ");
            scanf("%d",&e);
            insert(e);
            break;

        case 2:
            if(front==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n deleted Element is : %d ",delete());
            break;

        case 3:
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

void insert(int e)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
    }
    else
        rear=(rear+1)%MS;

    c_queue[rear]=e;
}

int delete()
{
    if(front==-1&&rear==-1)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    e=c_queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
        front=(front+1)%MS;

    return e;
}


int peek()
{
    if(front==-1&&rear==-1)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    e=c_queue[front];
    return e;
}

void display()
{
    int i;

    if(front==-1&&rear==-1)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    printf("\n The queue is as follows : ");

    for(i=front; i!=rear; i=(i+1)%MS)
    {
        printf("%d\n",c_queue[i]);
    }
    printf("%d\n",c_queue[i]);
}

