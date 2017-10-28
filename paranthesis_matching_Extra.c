#include<stdio.h>
#include<ctype.h>
#define MS 100
int top=-1,i;
char e;
void push(char);
char pop();
char stack[MS];
char s[MS];
int ismatch(char,char);
int main()
{

    printf("Enter the expression : ");
    gets(s);

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='{'||s[i]=='('||s[i]=='[')
        {
          push(s[i]);
        }


        else if(s[i]=='}'||s[i]==')'||s[i]==']')
        {
            if((top==-1))
            {
                printf("error : unbalanced paranthesis right more! ");
                return 0;
            }

            else
            {
                char a=pop();
                if(ismatch(a,s[i])!=1)
                {
                    printf("error : unbalanced paranthesis ! ");
                    return 0;
                }

            }

        }
    }
    if(top==-1)
	{
		printf("Balanced Parentheses\n");
		return 1;
	}
	else
	{
		printf("error : unbalanced paranthesis left more! ");
		return 0;
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
int ismatch(char a,char b)
{
    if (a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else
        return 0;

}

