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
    char s[100],b[100],j=0;
    printf("enter the expression : ");
    gets(s);
    int n=strlen(s);
    s[-1]='(';
    push(')');
    strcpy(b," ");
    for(i=n-1;i>=-1;i--)
    {
        if((s[i])>='a'&&s[i]<='z')
        {
            b[j]=s[i];
            j++;
            printf("%c",s[i]);

        }
        else if(s[i]==')')
        {
            push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(stack[top]!=')')
            {
                //b[j]= pop();
                //j++;
                printf("%c",pop());
            }

        }
        else
        {
            while(top!=-1 && stack[top]!=')' && getpriority(stack[top])>getpriority(s[i]))
            {

                //b[j] = pop();
                //j++;
                printf("%c",pop());

            }


            push(s[i]);


        }
    }



}
