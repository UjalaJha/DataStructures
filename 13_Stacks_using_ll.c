#include<stdio.h>
#define MS 5
void push(int);
int pop();
void display();
struct node *top=NULL, *ptr, *temp;
struct node
{
    int data;
    struct node *next;
};
struct node *newnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
};
void delnode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}
int c=0;
int main()
{
    int ch,e;

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
            if(c==MS)
            {
                printf("**OVERFLOW**");
                break;
            }
            printf("\n Enter Element to Push : ");
            scanf("%d",&e);
            push(e);
            break;

        case 2:
            if(top==NULL)
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
    temp=newnode();
    temp->data=e;
    temp->next=NULL;

    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
    c++;

}

int pop()
{
    int e=top->data;
    ptr=top;
    top=top->next;
    delnode(ptr);
    return e;
}


void display()
{
    ptr = top;

    if (ptr == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int peek()
{
    if(top==NULL)
    {
        printf("**EMPTY STACK**");
        return 0;
    }

    int e=top->data;
    return e;
}
