#include <stdio.h>

struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
    struct node *parent;
};

//functions
int isEmpty();
void insert();
struct node * search(struct node *, int);
void display(struct node *, int);
struct node* createNode();
void addData(struct node*);
int deleteNode(struct node*, int);
struct node* findmax(struct node*);
void travarsal(struct node*);
void inOrder(struct node*);
void preOrder(struct node*);
void postOrder(struct node*);



struct node * root=NULL;

int main()
{
    int ch;
    do
    {
        printf("\n\n===MENU===");
        printf("\n1 :   Insert");
        printf("\n2 :   Search");
        printf("\n3 :   Display");
        printf("\n4 :   Delete");
        printf("\n5 :   Traversal");
        printf("\n6 :   Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        fflush(stdin);

        switch(ch)
        {
            case 1:
                {
                    insert();
                }
                break;
            case 2:
                {
                    int data;
                    printf("\nEnter the data to be searched :");
                    scanf("%d", &data);
                    fflush(stdin);
                    struct node *ptr=NULL;
                    ptr=search(root, data);             //returns the node which holds the data
                    if(ptr!=NULL)                       //Node exists
                    {
                        printf("\nData Found %d", ptr->data);
                    }
                    else                                //No node returned
                        printf("\nData Not Found");
                }
                break;
            case 3:
                {
                    display(root,0);                    //display tree horizontally tilted and form the root
                }
                break;
            case 4:
                {

                    int data;
                    printf("\nEnter the data to be deleted :");
                    scanf("%d", &data);
                    fflush(stdin);
                    int flag=0;                         //iff deleted turns to 1
                    flag = deleteNode(root,data);       //starts from root
                    if(flag==1)
                        printf("\nEntered data has been deleted.");
                    else
                    {
                        printf("\nData Not Found");
                    }

                }
                break;
            case 5:
                {
                    travarsal(root);
                }
                break;
            case 6:
                {
                    printf("\nEXIT");
                }
                break;
            default:
                {
                    printf("\nInvalid Input");
                }
        }
    }while(ch!=6);
}

int isEmpty()
{
    return(root==NULL);
}


void insert()
{
    char ch;
    do
    {
        struct node *temp= createNode();
        addData(temp);

        struct node* ptr;
        if(isEmpty()==1)
        {
            root=temp;
            ptr=root;
        }
        else
        {
            ptr=root;
            while(1)
            {
                if(temp->data<=ptr->data)
                {
                    if(ptr->lChild==NULL)
                    {
                        ptr->lChild=temp;
                        temp->parent=ptr;
                        break;
                    }
                    else
                    {
                        ptr=ptr->lChild;
                    }
                }
                else if(temp->data > ptr->data)
                {
                    if(ptr->rChild==NULL)
                    {
                        ptr->rChild=temp;
                        temp->parent=ptr;
                        break;
                    }
                    else
                    {
                        ptr=ptr->rChild;
                    }
                }
            }
        }
        printf("\nDo you want to add one more node (Y for Yes) :");
        scanf("%c", &ch);
        fflush(stdin);
    }while(toupper(ch)=='Y');
}

struct node* createNode()
{
    return((struct node*)malloc(sizeof(struct node)));                              //returns pointer
}

void addData(struct node* temp)
{
    printf("\nEnter the data to be inserted : ");
    scanf("%d", &temp->data);
    fflush(stdin);
    temp->lChild=NULL;
    temp->rChild=NULL;
    temp->parent=NULL;
}

void display(struct node *x, int i)
{
    int j;
    if(x==NULL)
    {
        return;
    }

    display(x->rChild, i+1);
    for(j=0;j<i;j++)
    {
        printf("\t");
    }
    printf("%d", x->data);
    printf("\n\n");

    display(x->lChild,i+1);
}


struct node * search(struct node *p, int data)
{
    struct node *ptr = p;

    if(data==ptr->data)
        return ptr;
    else if(data<ptr->data)
    {
        if(ptr->lChild==NULL)
            return NULL;
        else
        {
            return(search(ptr->lChild, data));
        }
    }
    else
    {
        if(ptr->rChild==NULL)
        {
            return NULL;
        }
        else
        {
            return search(ptr->rChild,data);
        }
    }
}


int deleteNode(struct node *p, int data)
{
    if(root==NULL)
    {
        printf("\nTree is empty");                                                                                                                                                                                                    printf("\nEmpty Tree!");
        return 0;
    }
    struct node *ptr=p;

    while(ptr!=NULL && ptr->data!=data)            //Find the node with given data
    {
        if(data<=ptr->data)
            ptr=ptr->lChild;                        //search in left side tree
        else
            ptr=ptr->rChild;                        //search in right side tree
    }
    if(ptr==NULL)
    {
        printf("\nData Not Found in 2");
        return 0;
    }

    //To delete Leaf Node

    if(ptr->lChild==NULL  && ptr->rChild==NULL)     //true if it is a leaf node
    {
        if(ptr->parent==NULL)                       //Only node && root node
        {
            root=NULL;
            free(ptr);
            printf("\nEmpty tree");
            return 1;
        }
        if(ptr->parent->lChild==ptr)                //Left child
        {
            ptr->parent->lChild=NULL;               //make the lChild of parent NULL
            ptr=NULL;
            free(ptr);
            return 1;
        }
        if(ptr->parent->rChild==ptr)                //Right Child
        {
            ptr->parent->rChild=NULL;               //Make the rChild of parent NULL
            ptr=NULL;
            free(ptr);
            return 1;
        }
    }
    else if(ptr->lChild!=NULL)                      //It has left child
    {
        int val;
        struct node * ptr1=findmax(ptr->lChild);
        val=ptr1->data;
        deleteNode(ptr,ptr1->data);
        ptr->data=val;
    }
    else if(ptr==root)                                //delete root node
    {
        root=ptr->rChild;
        free(ptr);
    }
    else
    {
        if(ptr->parent->lChild==ptr)
        {
            ptr->parent->lChild=ptr->rChild;

        }
        else
        {
            ptr->parent->rChild=ptr->rChild;
        }
    }
    return 1;
}

struct node* findmax(struct node *p)
{
    if(p==NULL)
        return p;
    if(p->rChild==NULL)
        return p;
    return(findmax(p->rChild));
}

void travarsal(struct node *ptr)
{
    int ch;
    do
    {
        printf("\n\n===Travarsal Menu===");
        printf("\n1 : In-Order");
        printf("\n2 : Pre-Order");
        printf("\n3 : Post-Order");
        printf("\n4 : Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        fflush(stdin);

        switch(ch)
        {

            case 1:
                {
                    inOrder(ptr);
                }
                break;
            case 2:
                {
                    preOrder(ptr);

                }
                break;
            case 3:
                {
                    postOrder(ptr);

                }
                break;
            case 4:
                {
                    printf("\nExit");
                }
                break;
            default:
                {
                    printf("\nInvalid Input");
                }
        }

    }while(ch!=4);
}



void inOrder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    inOrder(ptr->lChild);
    printf("%d\t", ptr->data);
    inOrder(ptr->rChild);
}


void preOrder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    printf("%d\t", ptr->data);
    preOrder(ptr->lChild);
    preOrder(ptr->rChild);
}

void postOrder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    postOrder(ptr->lChild);
    postOrder(ptr->rChild);
    printf("%d\t", ptr->data);
}
