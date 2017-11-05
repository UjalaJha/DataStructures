#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode()
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    return node;
};
struct node *start=NULL;
struct node *end,*temp,*ptrbefore,*ptr;
int c;
void delnode(struct node *p)
{
    p->next=NULL;
    p->prev=NULL;
    free(p);

}
void insertat()
{
    int pos,data,i;
    printf("enter the location you want to insert at : ");
    scanf("%d",&pos);
    printf("enter data : ");
    scanf("%d",&data);
    temp=newnode();
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(pos==1)
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
        c++;
    }
    else
    {
        ptrbefore=start;
        for(i=0; i<pos-2; i++)
        {
            ptrbefore=ptrbefore->next;
        }
        temp->next=ptrbefore->next;
        temp->prev=ptrbefore;
        ptrbefore->next->prev=temp;
        ptrbefore->next=temp;
        c++;
    }


}
void insertbefore()
{
    int pos,data,i,num;
    printf("enter the value before which you want to insert : ");
    scanf("%d",&num);
    ptr=start;
    while(ptr!=NULL&&ptr->data!=num)
    {
        ptr=ptr->next;
    }
    printf("enter data : ");
    scanf("%d",&data);
    temp=newnode();
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(ptr==start)
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
        c++;
    }
    else
    {
        ptrbefore=start;
        while(ptrbefore!=NULL && ptrbefore->next!=ptr)
        {
            ptrbefore=ptrbefore->next;
        }
        temp->next=ptrbefore->next;
        temp->prev=ptrbefore;
        ptrbefore->next->prev=temp;
        ptrbefore->next=temp;
        c++;

    }




}
void deletevalue()
{
    int num;
    printf("Enter the data you want to delete :");
    scanf("%d",&num);
    ptr=start;
    while(ptr!=NULL&&ptr->data!=num)
    {
        ptr=ptr->next;
    }

    if(ptr->next!=NULL)
        ptr->next->prev=ptr->prev;
    if(ptr->prev!=NULL)
        ptr->prev->next=ptr->next;

    if(ptr==start)
    {
        start=start->next;
    }

    delnode(ptr);
}


create()
{
    int data;
    c=0;
    char choice;
    do
    {
        printf("enter the data : ");
        scanf("%d",&data);
        temp=newnode();
        temp->data=data;
        temp->next=NULL;
        temp->prev=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            end->next=temp;
            temp->prev=end;
        }
        end=temp;

        c++;
        printf("do you want to continue creating : ");
        scanf(" %c",&choice);
    }
    while(toupper(choice)=='Y');


}
void display()
{

    struct node *p;
    p=start;
    printf("\n------forward-------\n");
    while(p->next!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);

    printf("\n------backwards-------\n");
    p=end;
    while(p->prev!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
    printf("%d ",p->data);

}
int main()
{
    int opt;
    int ch;
    do
    {
        printf("\n**********************");
        printf("\n1. Create ");
        printf("\n2. Display ");
        printf("\n3. Insert at ");
        printf("\n4. Insert before ");
        printf("\n5. delete by value ");
        printf("\n**********************");
        printf("\nEnter choice : ");
        scanf("%d",&opt);
        printf("\n");
        switch(opt)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insertat();
            break;

        case 4:
            insertbefore();
            break;

        case 5:
            deletevalue();
            break;



        }

        printf("\ndo you want to continue : ");
        scanf(" %c",&ch);
    }
    while(toupper(ch)=='Y');
}


