#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode()
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    return node;
};
struct node *start1=NULL,*start2=NULL;
struct node *end1,*end2,*temp,*ptrbefore,*ptr;
void delnode(struct node *p)
{
    p->next=NULL;
    free(p);
}
create()
{
    int data;
    int c=0;
    char choice;
    do
    {
        printf("enter the data : ");
        scanf("%d",&data);
        temp=newnode();
        temp->data=data;
        temp->next=NULL;
        if(start1==NULL)
        {
            start1=temp;
        }
        else
        {
            end1->next=temp;
        }
        end1=temp;
        c++;
        printf("do you want to continue creating : ");
        scanf(" %c",&choice);
    }
    while(toupper(choice)=='Y');
}
void reverse()
{
    struct node *ptr, *nnode,*nnnode;

    ptr=nnode=nnnode=start1;
    nnode=ptr->next;
    nnnode=nnode->next;

    ptr->next=NULL;
    nnode->next=ptr;



    while(nnnode!=NULL)
    {
        ptr=nnode;
        nnode=nnnode;
        nnnode=nnnode->next;
        nnode->next =ptr;


    }
    start2=nnode;


}
split()
{
    int i,pos;
    printf("\nenter the point at which you want to split : ");
    scanf("%d",&pos);
    ptr=start1;
    for(i=0; i<pos-2; i++)
    {
        ptr=ptr->next;
    }
    start2=ptr->next;
    end1=ptr;
    ptr->next=NULL;
}
void copy()
{
    ptr=start1;
    while(ptr!=NULL)
    {

        temp=newnode();
        temp->data=ptr->data;
        temp->next=NULL;
        if(start2==NULL)
        {
            start2=temp;
        }
        else
        {
            end2->next=temp;
        }
        end2=temp;
        ptr=ptr->next;
    }


}
void display1()
{

    struct node *p;
    p=start1;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }

}
void display2()
{

    struct node *p;
    p=start2;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }

}
int main()
{
    int opt;
    int ch;
    do
    {
        printf("\n**********************");
        printf("\n1. Create ");
        printf("\n2. reverse");
        printf("\n3. split ");
        printf("\n4. concatenate ");
        printf("\n5. copy");
        printf("\n**********************");
        printf("\nEnter choice : ");
        scanf("%d",&opt);
        printf("\n");
        switch(opt)
        {
        case 1:
            create();
            display1();
            break;
        case 2:
            printf("original : \n");
            display1();
            reverse();
            printf("\nreversed : \n");
            display2();

            break;
        case 3:

            printf("original : \n");
            display1();
            split();
            printf("\nSplit 1 : \n");
            display1();
            printf("\nSplit 2 : \n");
            display2();
            break;

        case 4:
            //insertbefore();
            break;

        case 5:
            printf("original : \n");
            display1();
            copy();
            printf("\nCopied : \n");
            display2();
            break;



        }

    }
    while(opt!=6);
}
