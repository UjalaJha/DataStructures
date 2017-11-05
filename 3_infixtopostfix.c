#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MS 100
int top=-1;
char e;
char stack[MS];
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
getpriority(char c)
{
    if(c=='*'||c=='/'||c=='%')
        return 3;
    if(c=='+'||c=='-')
        return 2;
    else
        return 1;
}
int main()
{
    int i;
    char s[100];
    printf("enter the expression : ");
    gets(s);
    int len=strlen(s);
    s[len]=')';
    s[len+1]='\0';
    push('(');
    for(i=0; s[i]!='\0'; i++)
    {
        if((s[i])>='a'&&s[i]<='z')
        {
            printf("%c",s[i]);
        }
        else if(s[i]=='(')
        {
            push(s[i]);
        }
        else if(s[i]==')')
        {
            while(stack[top]!='(')
            {
                printf("%c", pop());
            }
        }
        else
        {
            while(top!=-1 && stack[top]!='(' && getpriority(stack[top])>=getpriority(s[i]))
            {

                printf("%c",pop());

            }


            push(s[i]);


        }
    }



}
