#include<stdio.h>
#define MS 5
int front=-1,rear=-1,e;
struct priority_queue
{
    int key;
    int element;
} pq[MS],temp;

void insert()
{
    int i;
    if(front==-1&&rear==-1)
    {
        front=rear=0;
    }
    else
        rear++;

    printf("Enter Priority ");
    scanf("%d",&pq[rear].key);
    printf("Enter element ");
    scanf("%d",&pq[rear].element);
    for(i=rear-1; i>=0; i--)
    {
        if(pq[i].key>pq[i+1].key)
        {
            temp = pq[i];
            pq[i]= pq[i+1];
            pq[i+1] = temp;
        }

    }


}

int deleteq()
{
    if(front==-1&&rear==-1)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    e=pq[front].element;
    if(front==rear)
    {
        front=rear=-1;
    }
    else
        front++;

    return e;
}


int minelement()
{
    if(front==-1&&rear==-1)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    e=pq[front].element;
    return e;
}
int minkey()
{
    if(front==-1&&rear==-1)
    {
        printf("**EMPTY QUEUE**");
        return;
    }

    e=pq[front].key;
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
    for(i=front; i<=rear; i++)
    {
        printf("%d\t",pq[i].element);
    }
}
int main()
{
    int ch;

    do
    {
        printf("\n---------- Priority Queue operations-----------");
        printf("\n 1. INSERT ");
        printf("\n 2. DELETE ");
        printf("\n 3. MIN ELEMENT ");
        printf("\n 4. MIN KEY ");
        printf("\n 5. DISPLAY ");
        printf("\n---------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(rear==MS-1)
            {
                printf("**OVERFLOW**");
                break;
            }

            insert();
            break;

        case 2:
            if(front==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n deleted Element is : %d ",deleteq());
            break;

        case 3:
            printf("\n MIN Element is : %d ",minelement());
            break;

        case 4:
            printf("\n MIN Key is : %d ",minkey());
            break;

        case 5:
            display();
            break;

        case 6:
            printf("\n Exiting......");
            break;
        }
    }
    while(ch!=7);
}


