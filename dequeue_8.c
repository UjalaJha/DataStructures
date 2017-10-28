#include<stdio.h>
#define MS 5
int front=-1,rear=-1,e;
void display();
int c_queue[MS];

void insertrear(int e)
{
    if(front==-1&&rear==-1)
    {
        front=rear=0;
    }
    else
        rear=(rear+1)%MS;

    c_queue[rear]=e;
}

void insertfront(int e)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else if(front==0)
    {
        front=MS-1;
    }
    else
    {
        front--;
    }


    c_queue[front]=e;
}

int deletefront()
{
    e=c_queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
        front=(front+1)%MS;

    return e;
}

int deleterear()
{

    e=c_queue[rear];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
        rear=(rear-1)%MS;

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

int  main()
{
    int choice;
    printf("\n----------Double Ended Queue operations-----------");
    printf("\n1: Input Restricted queue");
    printf("\n2: Output Restricted queue");
    printf("\n-------------------------------------------------");
    printf("\nEnter choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        input_restricted();
        break;

    case 2:
        output_restricted();
        break;

    }

}
void input_restricted()
{
    int ch;
    do
    {
        printf("\n----------input_restricted operations-----------");
        printf("\n 1. INSERT from rear");
        printf("\n 2. DELETE from front ");
        printf("\n 3. DELETE from rear ");
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
            insertrear(e);
            break;

        case 2:
            if(front==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n deleted front Element is : %d ",deletefront());
            break;

        case 3:
            if(rear==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n deleted rear Element is : %d ",deleterear());
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

void  output_restricted()
{
    int ch;
    do
    {
        printf("\n----------output_restricted queue operations-----------");
        printf("\n 1. INSERT from rear ");
        printf("\n 2. INSERT from front ");
        printf("\n 3. DELETE from front ");
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
            insertrear(e);
            break;

        case 2:
            if(front==(rear+1)%MS)
            {
                printf("**OVERFLOW**");
                break;
            }
            printf("\n Enter Element to insert : ");
            scanf("%d",&e);
            insertfront(e);
            break;

        case 3:
            if(front==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n deleted rear Element is : %d ",deletefront());
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



