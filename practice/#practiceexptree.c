#include<stdio.h>
#include<string.h>
struct tree
{
    char data;
    struct tree *right;
    struct tree *left;
};
struct tree *stack[20];
int top=-1;
struct tree *newnode()
{
    return (struct tree*)malloc(sizeof(struct tree));
};
void push(struct tree* p)
{
    stack[++top]=p;
}
struct tree *pop()
{
    return(stack[top--]);

};
int checkoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='^')
        return 2;
    else
        return 1;
}
void operand(char s)
{
    struct tree *node=newnode();
    node->data=s;
    node->left=NULL;
    node->right=NULL;
    push(node);
}
void operators(char s)
{
    struct tree *node=newnode();
    node->data=s;
    node->right=pop();
    node->left=pop();
    push(node);

}
void display(struct tree *x,int i)
{
   int j;
   if(x==NULL)
   {
       return;
   }
   display(x->right,i+1);
   for(j=0;j<i;j++)
   {
       printf("\t");
   }
   printf("%c",x->data);
   printf("\n\n");
   display(x->left,i+1);

}
void inorder(struct tree *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%c",node->data);
        inorder(node->right);
    }
}
int main()
{
    int i;
    char s[20];
    printf("enter the postfix expression : ");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(checkoperator(s[i])==1)
        {
            operand(s[i]);

        }
        else
        {
            operators(s[i]);
        }
    }
    printf("the tree is as follows : \n\n");
    struct tree *root;
    root=stack[top];
    display(root,0);
     printf("\nThe inorder traversal of the tree is \n");
    inorder(stack[top]);

}
