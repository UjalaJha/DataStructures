#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int c=0;
typedef struct node
{
    int data;
    struct node *next;
};
struct node *start1=NULL,*start2=NULL,*end1,*end2,*start,*ptr,*end;
struct node *newnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
};
void deletenode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}
void create(struct node **start)
{

    char choice;
    struct node *temp,*end;
    do
    {

        printf("\n enter data : ");
        temp=newnode();
        scanf("%d",&temp->data);
        temp->next=NULL;

        if(*start==NULL)
        {
            *start=temp;

        }
        else
        {
            end->next=temp;

        }
        end=temp;
        printf("\n Do you want to create another node : ");
        choice=getche();
    }
    while(choice=='y');

}
void concatenate()
{
    struct node *ptr;
    if(start1==NULL)
    {
        printf("\n Creating the First Linked List.\n");
        create(&start1);
        display(&start1);
    }


    printf("\n Creating the Second Linked List.\n");
    create(&start2);
    display(&start2);


    ptr = start1;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;

    }

    ptr->next = start2;

    printf("\nThe concatenated Linked List is: \n");
    display(&start1);


}
void display(struct node **start)
{
    printf("\n");
    if(*start == NULL)
        printf("Linked List is Empty.\n");
    else
    {
        ptr = *start;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void reverse()
{

    struct node *ptr,*nnode,*nnnode;

    nnnode=nnode=ptr=start1;
    nnnode=nnnode->next->next;
    nnode=nnode->next;

    ptr->next=NULL;
    nnode->next=ptr;

    while (nnnode!=NULL)
    {
        ptr=nnode;
        nnode=nnnode;
        nnnode=nnnode->next;
        nnode->next=ptr;


    }
    start1=nnode;

    printf(" Reversed Linked List ");
    display(&start1);
}
void copy()
{
    struct node *ptr1,*end2,*temp;

    if(start1 == NULL)
        return;
    else
    {
        ptr1 = start1;
        while(ptr1 != NULL)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->data = ptr1->data;
            temp->next = NULL;

            if(start2 == NULL)
                start2 = temp;
            else
            {
                end2->next = temp;

            }
            end2 = temp;

            ptr1 = ptr1->next;
        }
    }
    printf("\n original Linked List ");
    display(&start1);
    printf("\n copied Linked List ");
    display(&start2);

}
void split()
{
    struct node *end;
    int num,i;
    if(start1 == NULL)
    {
        printf("Linked list not created ");
    }

    printf("Enter the position at which the list is to be splitted:  ");
    scanf("%d",&num);


    ptr = start1;
    for(i=1; i<num; i++)
    {
        ptr = ptr->next;
    }
    start2=ptr->next;
    ptr->next=NULL;
    printf("First split list : ");
    display(&start1);
    printf("Second split list : ");
    display(&start2);
}

main()
{
    char ch;
    do
    {
        printf("\n\n*****MENU*****");
        printf("\n1 : Create");
        printf("\n2 : Reverse");
        printf("\n3 : copy");
        printf("\n4 : concatenate");
        printf("\n5 : Split");
        printf("\n6 : Exit");
        printf("\n****************\n");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create(&start1);
            display(&start1);
            break;

        case 2:
            reverse();
            break;


        case 3:
            copy();
            break;
        case 4:
            concatenate();
            break;
        case 5:
            split();
            break;
        case 6:
            printf("Exiting.....");
            break;
        }

    }
    while(ch!=6);

}
