#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
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

}void printinorder(struct node *node)
{
    if(node==NULL)
        return;

    printinorder(node->left);
    printf("%d ", node->data);
    printinorder(node->right);

}

int main()
{
     struct node *root  = newnode(1);
     root->left = newnode(2);
     root->right = newnode(3);
     root->right->left = newnode(8);
     root->right->right = newnode(9);
     root->left->left = newnode(4);
     root->left->right = newnode(5);
     root->left->left->left = newnode(6);
     root->left->left->right = newnode(7);

     printf("\nPreorder traversal of binary tree is \n");
     printpreorder(root);

     printf("\nInorder traversal of binary tree is \n");
     printinorder(root);

     printf("\nPostorder traversal of binary tree is \n");
     printpostorder(root);

     getchar();
     return 0;
}
