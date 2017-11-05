#include<stdio.h>
#define MS 6
int topA=-1;
int topB=MS;
int e;
int stack[MS];
void pushA(int e)
{
   stack[++topA]=e;
}
void pushB(int e)
{
    stack[--topB]=e;
}
int popA()
{
    e=stack[topA--];
    return e;
}
int popB()
{
    e=stack[topB++];
    return e;
}
void displayA()
{
    int i;
    if(topA==-1)
        printf("\n Stack A is Empty");
    else
    {
        printf("\n Stack A : ");
        for(i=topA; i>=0; i--)
            printf("\t%d",stack[i]);
    }
}
void displayB()
{
    int i;
    if(topB==MS)
        printf("\n Stack B is Empty");
    else
    {
        printf("\n Stack B : ");
        for(i=topB; i<MS; i++)
            printf("\t%d",stack[i]);
    }
}

int main()
{
    int ch, val, e;

    do
    {
        printf("\n----------Multistack operations-----------");
        printf("\n 1. PUSH IN STACK A");
        printf("\n 2. PUSH IN STACK B");
        printf("\n 3. POP FROM STACK A");
        printf("\n 4. POP FROM STACK B");
        printf("\n 5. DISPLAY STACK A");
        printf("\n 6. DISPLAY STACK B");
        printf("\n 7. EXIT");
        printf("\n------------------------------------------------");
        printf("\n Enter your choice ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            if(topA==topB-1)
            {
                printf("overflow");
                break;
            }
            else
            {
                printf("enter the data to be pushed in A ");
                scanf("%d",&e);
                pushA(e);
            }
            break;
        case 2:
              if(topB==topA+1)
            {
                printf("overflow");
                break;
            }
            else
            {
                printf("enter the data to be pushed in B ");
                scanf("%d",&e);
                pushB(e);
            }
            break;
        case 3:
            if(topA==-1)
            {
                printf("Underflow");
                break;
            }
            else
            {
                printf("data to be popped out of A = %d",popA());
            }
            break;
          case 4:
            if(topB==MS)
            {
                printf("Underflow");
                break;
            }
            else
            {
                printf("data to be popped out of B = %d",popB());
            }
            break;
        case 5:
            displayA();
            break;

        case 6:
            displayB();
            break;

        }

    }while(ch!=7);

}
