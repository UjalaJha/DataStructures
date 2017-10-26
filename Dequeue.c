//Program to implement double ended queue

#include<stdio.h>
#define MS 5

int left=-1,right=-1,queue[MS];

void insertleft(int a)
{
    if(left==(right+1)%MS)
    {
        printf("Overflow");
        return;
    }
    if(left==-1 && right==-1)
        left=right=0;
    else if(left==0)
        left=MS-1;
    else
        left--;
    queue[left]=a;
}

void insertright(int a)
{
    if(left==(right+1)%MS)
    {
        printf("Overflow");
        return;
    }
    if(left==-1 && right==-1)
        left=right=0;
    else
        right=(right+1)%MS;
    queue[right]=a;
}

int deleteleft()
{
    int a;
    a=queue[left];
    if(right==left)
        right=left=-1;
    else
        left=(left+1)%MS;
    return a;
}

int deleteright()
{
    int a;
    a=queue[right];
    if(right==left)
        left=right=-1;
    else if(right==0)
        right=MS-1;
    else
        right--;
    return a;

}

void display(int front,int rear)
{

    if(front==-1)
        {
            printf("\nQueue is empty");
            return;
        }
    while(front!=-1)
    {
        printf("%d\n",queue[front]);
        if(front==rear)
            front=-1;
        else
            front=(front+1)%MS;
    }

}

void input_resticted()
{
    int a,b;
    while(a!=5)
    {
        printf("\n***Input Restricted Queue***");
        printf("\n1: Insert");
        printf("\n2: Delete from left");
        printf("\n3: Delete from right");
        printf("\n4: Display");
        printf("\n5: Exit");
        printf("\nEnter choice :-");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
            printf("\nEnter number to be inserted into the queue :-");
            scanf("%d",&b);
            insertright(b);
            break;

        case 2:
            if(left==-1)
                printf("\nUnderflow");
            else
                printf("The deleted element is %d",deleteleft());
            break;

        case 3:
            if(right==-1)
                printf("\nUnderflow");
            else
                printf("The deleted element is %d",deleteright());
            break;

        case 4:
            display(left,right);
            break;

        case 5:
            break;
        }
    }

}

void output_resticted()
{
    int a,b;
    while(a!=5)
    {
        printf("\n***Output Restricted Queue***");
        printf("\n1: Insert from left");
        printf("\n2: Insert from right");
        printf("\n3: Delete");
        printf("\n4: Display");
        printf("\n5: Exit");
        printf("\nEnter choice :-");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
            printf("\nEnter number to be inserted into the queue :-");
            scanf("%d",&b);
            insertleft(b);
            break;

        case 2:
            printf("\nEnter number to be inserted into the queue :-");
            scanf("%d",&b);
            insertright(b);
            break;

        case 3:
            if(left==-1)
                printf("\nUnderflow");
            else
                printf("The deleted element is %d",deleteleft());
            break;

        case 4:
            display(left,right);
            break;

        case 5:
            break;
        }
    }

}

main()
{
    int a;
    printf("*****Main Menu*****");
    printf("\n1: Input Restricted queue");
    printf("\n2: Output Restricted queue");
    printf("\nEnter choice :-");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
            input_resticted();
            break;

        case 2:
            output_resticted();
            break;

        }

}
