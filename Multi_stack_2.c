#include <stdio.h>
#define MAX 5
int stack[MAX],topA=-1,topB=MAX;

void pushA(int e)
{
    topA++;
    stack[topA]=e;
}
void pushB(int e)
{
    topB--;
    stack[topB] = e;

}

int popA()
{
    int e = stack[topA];
    topA--;
    return e;
}

int popB()
{

    int e = stack[topB];
    topB++;
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
    if(topB==MAX)
        printf("\n Stack B is Empty");
    else
    {
        printf("\n Stack B : ");
        for(i=topB; i<MAX; i++)
            printf("\t%d",stack[i]);
    }
}


int main()
{
    int ch, val, e;

    do
    {
        printf("\n----------MultistackStack operations-----------");
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
                printf("\n OVERFLOW");
                break;
            }
            printf("\n Enter Element to Push on stack A: ");
            scanf("%d",&e);
            pushA(e);
            break;

        case 2:
            if(topB==topA+1)
            {
                printf("\n OVERFLOW");
                break;
            }

            printf("\n Enter Element to Push on stack B: ");
            scanf("%d",&e);
            pushB(e);
            break;

        case 3:
            if(topA==-1)
            {
                printf("**UNDERFLOW**");
                break;
            }
            else
                printf("\n Popped Element is : %d ",popA());
            break;


        case 4:
            if(topB==MAX)
            {
                printf("**UNDERFLOW**");
                break;
            }
            else
                printf("\n Popped Element is : %d ",popB());
            break;

        case 5:
            displayA();
            break;

        case 6:
            displayB();
            break;

        case 7:
            printf("\n Exiting......");
            break;
        }
    }
    while(ch!=7);

}
