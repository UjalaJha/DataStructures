#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int c=0;
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *newnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
};
void deletenode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}
void insertat()
{
    int p,i;
    struct node *ptr,*temp;
    if(start==NULL)
    {
        printf("linked list not created");
    }
    printf("\nenter the position at which to be inserted : ");
    scanf("%d",&p);
    if(p>c)
    {
        return;
    }
    temp=newnode();
    printf("\n enter the data = ");
    scanf("%d",&temp->data);

    if(p==1)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
      ptr=start;
      for(i=1;i<=p-2;i++)
      {

          ptr=ptr->next;
      }
      temp->next=ptr->next;
      ptr->next=temp;
    }

}
void insertbefore()
{
    int num;
    struct node *ptr,*temp,*ptrBefore;
    if(start==NULL)
    {
        printf("linked list not created");
    }
        else
    {
        printf("\nenter the value before which to be inserted");
        scanf("%d",&num);
         ptr=start;
        int pos=1;
        while(ptr->data!=num&&ptr->next!=NULL)
        {
            ptr=ptr->next;
            pos++;

        }
        if((ptr->data)==num)
        {
            printf("\nelement found at %d",pos);
            temp=newnode();
            printf("\n enter the data = ");
            scanf("%d",&temp->data);
            if(ptr==start)
            {
                temp->next=start;
                start=temp;
            }
            else
            {
            ptrBefore=start;
            while(ptrBefore->next!=ptr)
            {
                ptrBefore=ptrBefore->next;
            }
            temp->next=ptr;
            ptrBefore->next=temp;

            }
        }
        else
        {
            printf("\nelement not found");
            return;
        }

    }
}
void insertafter()
{
    int num;
    struct node *ptr,*temp;
    if(start==NULL)
    {
        printf("linked list not created");
    }
    else
    {
        printf("\nenter the value after which to be inserted");
        scanf("%d",&num);

        ptr=start;
        int pos=1;
        while(ptr->data!=num&&ptr->next!=NULL)
        {
            ptr=ptr->next;
            pos++;

        }
        if((ptr->data)==num)
        {
            printf("\nelement found at %d",pos);
            temp=newnode();
            printf("\n enter the data = ");
            scanf("%d",&temp->data);
            temp->next=ptr->next;
            ptr->next=temp;

        }
        else
        {
            printf("\nelement not found");
            return;
        }





    }
}
void deletevalue()
{
    if(start==NULL)
    {
        printf("linked list not created");
    }
    else
    {
        int num;
        struct node *ptr;
        struct node *ptrAt,*ptrBefore,*temp;
        printf("\nenter the value to be deleted");
        scanf("%d",&num);

        ptr=start;
        int pos=1;
        while(ptr->data!=num&&ptr->next!=NULL)
        {
            ptr=ptr->next;
            pos++;

        }
        if((ptr->data)==num)
        {
            printf("\nelement found at %d",pos);
            ptrAt=ptr;
        }


        if(ptrAt==start)
        {
            start=start->next;
            ptrAt->next=NULL;
            free(ptrAt);
        }
        else
        {
            ptrBefore=start;
            while(ptrBefore->next!=ptrAt)
            {
                ptrBefore=ptrBefore->next;
            }

            ptrBefore->next=ptrAt->next;
            ptrAt->next=NULL;
            free(ptrAt);
        }
    }

}
void deleteposition()
{
    if(start==NULL)
    {
        printf("linked list not created");
    }
    else
    {
        int pos,i;
        struct node *ptr;
        struct node *ptrAt,*ptrBefore,*temp;
        printf("\nenter the position to be deleted : ");
        scanf("%d",&pos);

        ptrAt=start;
        for(i=1;i<=pos-1;i++)
        {

            ptrAt=ptrAt->next;
        }


        if(ptrAt==start)
        {
            start=start->next;
            ptrAt->next=NULL;
            free(ptrAt);
        }
        else
        {
            ptrBefore=start;
            while(ptrBefore->next!=ptrAt)
            {
                ptrBefore=ptrBefore->next;
            }

            ptrBefore->next=ptrAt->next;
            ptrAt->next=NULL;
            free(ptrAt);
        }
    }
}
void create()
{

    char choice;
    struct node *temp,*end;
    do{

        printf("\n enter data : ");
        temp=newnode();
        scanf("%d",&temp->data);
        temp->next=NULL;

        if(start==NULL)
        {
            start=temp;

        }
        else
        {
            end->next=temp;

        }
        end=temp;
        c++;

        printf("\n Do you want to create another node : ");
        choice=getche();

        }while(choice=='y');
        printf("\ncount = %d",c);
}
void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n Linked list is empty");
    }
    else
    {
        printf("\n the linked list is as follows : ");
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}
void search()
{
    int dt;
    printf("\n enter the element to be searched ");
    scanf("%d",&dt);

    struct node *ptr;
    if(start==NULL)
    {
        printf("\n Linked list is empty");
    }
    else
    {
        int flag=0;
        ptr=start;
        int pos=1;
        while(ptr!=NULL)
        {
            if((ptr->data)==dt)
            {
                printf("element found at pos =%d ",pos);
                flag=1;
                break;

            }

            else
            {
                ptr=ptr->next;
            }
            pos++;

        }
        if (flag==0)
        {
            printf("\n element not found");
        }
    }

}
main()
{
    char ch;
    do
    {
        printf("\n*****MENU*****");
        printf("\n1 : Create");
        printf("\n2 : Insert");
        printf("\n3 : Delete");
        printf("\n4 : Search");
        printf("\n5 : Display");
        printf("\n6 : Exit");
        printf("\n****************\n");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                {

                char ch;
                printf("\n1. Insert at a position");
                printf("\n2. Insert after a value");
                printf("\n3. Insert before a value");
                printf("\nEnter Choice : ");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                        insertat();
                        break;
                    case 2:
                        insertafter();
                        break;
                    case 3:
                        insertbefore();
                        break;
                }
                }
                break;


            case 3:
                {
                    char c;
                    printf("\n1. Delete by value");
                    printf("\n2. delete by position");
                    printf("\nEnter Choice");
                    scanf("%d",&c);
                    switch(c)
                    {
                        case 1:
                            deletevalue();
                            break;
                        case 2:
                            deleteposition();
                            break;
                    }
                }
                break;


            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting.....");
                break;
        }

    }while(ch!=6);

}
