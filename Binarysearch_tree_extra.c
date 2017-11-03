#include<stdio.h>
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
    char choice='Y';
    int num;
    p = newnode();
    do{
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

        while(1==1)
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
        scanf("%c", &choice);
        fflush(stdin);
    }while(toupper(choice)=='Y');

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
    void main()
    {
        int n,num;
        char ch;
        do
        {
            printf("\n\n-------MENU--------");
            printf("\n1 : Create Tree");
            printf("\n2 : Display Tree");
            printf("\n3 : InOrder Traversal");
            printf("\n4 : PostOrder Traversal");
            printf("\n5 : PreOrder Traversal");
            printf("\n6 : Exit");

            printf("\n\nEnter your choice : ?");
            scanf("%d",&n);

            switch(n)
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
                printf("\nTerminating...");
                break;

            }
        }
        while(n!=6);
    }
