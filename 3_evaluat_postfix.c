#include<stdio.h>
#include<ctype.h>
#define MS 100
int top=-1,e;
void push(int);
int pop();
int peek();
void display();
int stack[MS];
char s[MS];
main()
{
    int n,i,op1,op2,res;
    printf("Enter the postfix expression : ");
    gets(s);

    for(i=0;s[i]!='\0';i++)
    {
        if(isdigit(s[i]))
            push(s[i]-'0');
        else
        {

            op2=pop();
            op1=pop();
            switch(s[i])
            {
                case '+':
                res=op1+op2;
                break;

                case '-':
                res=op1-op2;
                break;

                case '*':
                res=op1*op2;
                break;

                case '/':
                res=op1/op2;
                break;
            }
            push(res);
        }
    }
    printf("result is : %d",peek());
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
    return;
    }

    e=stack[top];
    return e;
}
