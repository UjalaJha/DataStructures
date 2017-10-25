PFA
#include<stdio.h>

#define MS 100

int stack[100];
int top=-1;
void push();
int pop();
void display();

int main()
{
    int stack[100];
    int ch;
    int c;
    do
    {
        printf("---------------------------\n");
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("---------------------------\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                push();
                break;
            case 2:
                if(top == -1)
                {
                    printf("Underflow!!");
                    break;
                }
                printf("The popped element is : %d",pop());
                break;
            case 3:
                display();
                break;
        }
        printf("do you want to continue enter 1 to continue\n");
        scanf("%d",&c);
    }while(c==1);
}
void push()
{
    int e;

    while(top == MS-1)
    {
        printf("overflow");
        return ;
    }
    printf("enter the element to be pushed :");
    scanf("%d",&e);
    top++;
    stack[top]=e;
}
int pop()
{
    int e;
    e=stack[top];
    top--;
    return e;

}
void display()
{
    int i;
    printf("Stack is\n");
    for (i = top; i >= 0; i--)
        {
            printf ("%d\n", stack[i]);
        }

}
