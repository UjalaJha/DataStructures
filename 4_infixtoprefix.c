#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MS 100
int top=-1;
int tops=-1;
char e;
char stack[MS];
char strings[MS];
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
void pushs(char e)
{
    tops++;
    strings[tops]=e;
}

char pops()
{
    e=strings[tops];
    tops--;
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
    strcpy(b,"");
    for(i=n-1;i>=-1;i--)
    {
        if((s[i])>='a'&&s[i]<='z')
        {
            pushs(s[i]);

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
                pushs(pop());
            }

        }
        else
        {
            while(top!=-1 && stack[top]!=')' && getpriority(stack[top])>getpriority(s[i]))
            {

                //b[j] = pop();
                //j++;
                 pushs(pop());

            }


            push(s[i]);


        }
    }
    printf("prefix exp : ");
     while(tops!=-1)
        {
            printf("%c",pops());
        }



}
