#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode()
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    return(node);

};
struct node *root=NULL;

void inorder(struct node *x)
{
    if(x==NULL)
    {
        return;
    }
    inorder(x->left);
    printf("%d",x->data);
    inorder(x->right);
}
void preorder(struct node *x)
{
    if(x==NULL)
    {
        return;
    }
    printf("%d",x->data);
    preorder(x->left);
    preorder(x->right);
}
void postorder(struct node *x)
{
    if(x==NULL)
    {
        return;
    }
    postorder(x->left);
    postorder(x->right);
    printf("%d",x->data);

}
void display(struct node *x,int i)
{
    int j;
    if(x==NULL)
    {
        return;
    }
    display(x->right,i+1);
    for(j=0; j<i; j++)
    {
        printf("\t");
    }
    printf("%d",x->data);
    printf("\n\n");
    display(x->left,i+1);
}
void create()
{
    struct node *p,*q;
    int data;
    char choice;
    do
    {
        printf("Enter data : ");
        scanf("%d",&data);
        p=newnode();
        p->data=data;
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
                        q=q->left;
                }
                else
                {

                    if(q->right==NULL)
                    {
                        q->right=p;
                        break;
                    }
                    else
                        q=q->right;

                }

            }

        }
        printf("do you want to continue : ");
        scanf(" %c",&choice);

    }
    while(toupper(choice)=='Y');

    display(root,0);

}
void search(struct node *x,int num)
{
    struct node *q=x;
    if(root==NULL)
    {
        printf("Empty tree !");
    }
    while(q!=NULL && q->data!=num)
    {
        if(num<=q->data)
            q=q->left;
        else
            q=q->right;
    }
    if(q==NULL)
    {
        printf("data not found !");
    }
    else if(q->data==num)
    {
        printf("data found .. ");
    }
}
struct node*parent (struct node *x)
{
    struct node *p=root;
    if(x==p)
    {
        return NULL;
    }
    else
    {
        while(p!=NULL)
        {
            if (p->left==x || p->right==x)
            {
                return p;
            }
            if(x->data<=p->data)
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }
        }

    }
}
struct node *max(struct node *x)
{
    if(x==NULL)
        return x;
    else if(x->right == NULL)
        return x;

    return max(x->right);
}
int deletenode(struct node *x,int n)
{
    struct node *q=x,*p;
    if(root==NULL)
    {
        printf("Empty tree !");
    }
    while(q!=NULL && q->data!=n)
    {
        if(n<=q->data)
            q=q->left;
        else
            q=q->right;
    }
    if(q==NULL)
    {
        printf("data not found !");
        return 0;
    }
    else if(q->data==n)
    {
        printf("data found .. ");
    }
    if(q->left == NULL && q->right == NULL)
    {
        if(parent(q)==NULL)
        {
            root=NULL;
            return 1;
        }
        if(parent(q)->left==q)
        {
            parent(q)->left=NULL;
            free(q);
            return 1;
        }
        else
        {
            parent(q)->right=NULL;
            free(q);
            return 1;
        }
    }
    if(q->left!=NULL)
    {
        struct node *ptr;
        int val;

        ptr=max(q->left);
        val=ptr->data;
        deletenode(q,val);
        q->data=val;
        return 1;
    }
    else if(q==root)
    {
        root=p->right;
        free(root);
    }
    else  //has only right
    {
       if(parent(q)->left=q)
       {
           parent(q)->left=q->right;
       }
       else
        {
           parent(q)->right=q->right;
       }
    }


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
            inorder(root);
            break;
        case 4 :
            if(root==NULL)
            {
                printf("\nNo element is present.");
                break;
            }
            postorder(root);
            break;
        case 5 :
            if(root==NULL)
            {
                printf("\nNo element is present.");
                break;
            }
            preorder(root);
            break;
        case 6 :
            printf("enter element to search : ");
            scanf("%d",&num);
            search(root,num);
            break;


        case 7 :
            printf("enter the element to be deleted : ");
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
            break;


        }
    }
    while(ch!=8);
}
