#include<stdio.h>
#define MS 5
int top=-1,e;
void push(int);
int pop();
int peek();
void display();
int stack[MS];

int main()
{
    int ch;

    do
    {
        printf("\n----------Stack operations-----------");
        printf("\n 1. PUSH ");
        printf("\n 2. POP ");
        printf("\n 3. PEEK ");
        printf("\n 4. DISPLAY ");
        printf("\n 5. EXIT ");
        printf("\n---------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(top==MS-1)
            {
                printf("**OVERFLOW**");
                break;
            }
            printf("\n Enter Element to Push : ");
            scanf("%d",&e);
            push(e);
            break;

        case 2:
            if(top==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            printf("\n Popped Element is : %d ",pop());
            break;

        case 3:
            printf("\n Topmost Element is : %d ",peek());
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
void push(int e)
{
    top++;
    stack[top]=e;
}

int pop()
{
    e=stack[top];
    top--;
    return e;
}

int peek()
{
    if(top==-1)
    {
        printf("**EMPTY STACK**");
        return 0;
    }

    e=stack[top];
    return e;
}

void display()
{
    int i;

    if(top==-1)
    {
        printf("**EMPTY STACK**");
        return ;
    }

    printf("\n The Stack is as follows : ");
    for(i=top; i>=0; i--)
    {
        printf("%d\t",stack[i]);
    }
}
