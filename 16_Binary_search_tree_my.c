#include<stdio.h>
#include<process.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
struct node *newnode()
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    return(node);

};
void printpostorder(struct node *node)
{
    if(node==NULL)
        return;

    printpostorder(node->left);
    printpostorder(node->right);
    printf("%d ", node->data);
}
void printpreorder(struct node *node)
{
    if(node==NULL)
        return;

    printf("%d ", node->data);
    printpreorder(node->left);
    printpreorder(node->right);

}
void printinorder(struct node *node)
{
    if(node==NULL)
        return;

    printinorder(node->left);
    printf("%d ", node->data);
    printinorder(node->right);

}
void create()
{
    struct node *p,*q;
    char choice;
    int num;

    do
    {
        p = (struct node*)malloc(sizeof(struct node));
        printf("enter the data : ");
        scanf("%d",&num);

        p->data =num;
        p->left=NULL;
        p->right=NULL;

        if(root==NULL)
        {
            root=p;
        }
        else
        {
            q=root;

            for(;;)
            {
                if(p->data<=q->data)
                {
                    if(q->left==NULL)
                    {
                        q->left=p;
                        break;
                    }
                    else
                        q= q->left;

                }
                else
                {
                    if(q->right==NULL)
                    {
                        q->right=p;
                        break;
                    }
                    else
                    {
                        q=q->right;
                    }
                }

            }

        }
        printf("\nDo you want to add one more node (Y for Yes) :");
        scanf(" %c", &choice);
    }
    while(toupper(choice)=='Y');

}

void display(struct node *x, int i)
{
    int j;
    if(x==NULL)
    {
        return;
    }

    display(x->right, i+1);
    for(j=0; j<i; j++)
    {
        printf("\t");
    }
    printf("%d", x->data);
    printf("\n\n");

    display(x->left,i+1);
}
struct node *search(struct node *x,int num)
{
    if(x==NULL)
    {
        printf("Data not found ");
        return;

    }
    if(x->data==num)
    {
        return x;
    }
    if(num<=root->data)
    {
        if(x->left==NULL)
        {
            return;
        }

        else
            return search(x->left,num);
    }
    else
    {
        if(x->right==NULL)
        {
            return;
        }
        else
            return search(x->right,num);
    }
}
struct node *parent(struct node * p)
{
    struct node * q;
    if(p==root)
        return NULL;
    q=root;
    while(q!=NULL)
    {
        if(q->left==p||q->right==p)
            return q;
        if(p->data <= q->data)
            q=q->left;
        else
            q=q->right;
    }
    return q;
}
int isleft(struct node *p)
{
    struct node *q;
    q=parent(p);
    if(q==NULL)
    {
        return 0;
    }
    else if(q->left==p)
    {
        return 1;
    }

    return 0;

}
struct node *findmax(struct node *p)
{
    if(p==NULL)
        return p;
    if(p->right==NULL)
        return p;

    return findmax(p->right);
}
int deletenode(struct node *t,int num)
{

    struct node *p;
    if(root==NULL)
    {
        printf("\nTree Is Empty.....");
        return 0;
    }
    p=t;

    while(p!=NULL&&p->data!=num)
    {
        if(num<=p->data)
            p=p->left;
        else
            p=p->right;

    }

    if(p==NULL)
    {
        printf("ELEMENT NOT FOUND...\n");
        return 0;
    }

    if(p->left==NULL&&p->right==NULL)
    {
        if(parent(p)==NULL)
        {
            root=NULL;
            return 1;
        }
        if(isleft(p))
        {
            parent(p)->left=NULL;
            p=NULL;
            free(p);
            return 1;
        }
        else
        {
            parent(p)->right=NULL;
            p=NULL;
            free(p);
            return 1;
        }
    }
    else if(p->left!=NULL)
    {
        int val;
        struct node * ptr;

        ptr=findmax(p->left);
        val=ptr->data;
        deletenode(p,ptr->data);
        p->data=val;
        return 1;
    }
    else if(p==root)
    {
        root=p->right;
        free(p);
    }
    else
    {
        if(isleft(p))
        {
            parent(p)->left=p->right;
        }
        else
        {
            parent(p)->right=p->right;
        }
    }
    return 1;


}



void main()
{
    int n,num,ch;

    do
    {
        printf("\n\n-------MENU--------");
        printf("\n1 : Create Tree");
        printf("\n2 : Display Tree");
        printf("\n3 : InOrder Traversal");
        printf("\n4 : PostOrder Traversal");
        printf("\n5 : PreOrder Traversal");
        printf("\n6 : Search ");
        printf("\n7 : Delete ");
        printf("\n8 : Exit ");

        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1 :

            create();
            break;
        case 2 :
            if(root==NULL)
            {
                printf("\nTree is Empty");
                break;
            }
            display(root,0);
            break;
        case 3 :
            if(root==NULL)
            {
                printf("\nNo element is present.");
                break;
            }
            printinorder(root);
            break;
        case 4 :
            if(root==NULL)
            {
                printf("\nNo element is present.");
                break;
            }
            printpostorder(root);
            break;
        case 5 :
            if(root==NULL)
            {
                printf("\nNo element is present.");
                break;
            }
            printpreorder(root);
            break;
        case 6 :

            printf("enter the value you want to search : ");
            scanf("%d",&num);
            struct node *ptr=NULL;
            ptr=search(root, num);
            if(ptr!=NULL)
            {
                printf("\nData Found %d", ptr->data);
            }
            else
                printf("\nData Not Found");
            break;

        case 7 :

            printf("enter data to be deleted : ");
            scanf("%d",&n);
            int flag=0;
            flag=deletenode(root,n);
            if(flag==1)
            {
                printf("element deleted \n");
                display(root,0);
            }
            else if(flag==0)
                printf("element not found");
        }
    }
    while(ch!=8);
}
