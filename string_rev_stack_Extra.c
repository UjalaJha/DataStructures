#include<stdio.h>
#include<string.h>
#define MS 100
int top=-1;
char e;
void push(char);
char pop();
char stack[MS];

int main()
{
    char e,s[100];
    int n,i;
    printf("enter string : ");
    gets(s);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        if(top==MS-1)
            {
                printf("**OVERFLOW/Long string**\n");
                break;
            }
        else
        push(s[i]);
    }

    if(top==-1)
        printf("empty stack/string ");
    else
        while(top!=-1)
        {
            //printf("%d",top);
            printf("%c",pop());
        }
}


void push(char e)
{
    top++;
    stack[top]=e;
}

char pop()
{
    e=stack[top];
    top--;
    return e;
}


