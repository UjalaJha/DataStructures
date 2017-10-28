#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int c=0;
struct node
{
    int data;
    struct node *next;
};
void deletenode(struct node *ptr)
{
    ptr->next=NULL;
    free(ptr);
}
struct node *start=NULL;
struct node *newnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
};
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
            while(ptrAt->next!=start)
            {
                 ptrAt=ptrAt->next;
            }
            ptrAt->next=start->next;
            free(start);
            start=ptrAt->next;
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

}
void insertat()
{
    int p,i;
    struct node *ptr,*temp,*end;
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
    printf("\n enter the data ");
    scanf("%d",&temp->data);

    if(p==1)
    {
        end=start;
        while(end->next!=start)
        {
            end=end->next;
        }


          end->next=temp;
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

}
void insertafter()
{

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
        end->next=start;
        c++;

        printf("\n Do you want to create another node : ");
        choice=getche();

        }while(choice=='y');
        printf("\ncount = %d",c);
}
void display()
{
    struct node *ptr;
    ptr=start;
    while((ptr->next)!=start)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\t",ptr->data);
}
void search()
{
    int dt;
    int flag=0;
    printf("\n enter the element to be searched ");
    scanf("%d",&dt);

    struct node *ptr;
    if(start==NULL)
    {
        printf("\n Linked list is empty");
    }
    else
    {

        ptr=start;
        int p=2;
        if(dt==start->data)
        {
            printf("element found at locn 1: ");
        }
        while(ptr->next!=start)
        {
            if(ptr->data==dt)
            {
                printf("Found at location %d",p);
                flag=1;
                break;
            }

            else
            {
                ptr=ptr->next;
            }
            p++;
        }



    }
        if (flag==0)
        {
            printf("\n element not found");
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
