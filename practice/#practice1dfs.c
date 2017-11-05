#include<stdio.h>
#define MS 100
#define visited 1
#define unvisited 0
int state[MS];
int adj[MS][MS];
int stack[MS];
int top=-1;
int i,j;
void push(int vertex)
{
    stack[++top]=vertex;
}
int pop()
{
    int vertex=stack[top--];
    return vertex;
}
int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}
int peek()
{
    return stack[top];
}
void creategraph(int v)
{
    printf("input adj matrix : \n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("inputed adj matrix : \n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}
void DFS_traversal(int v)
{
    int start;
    for(i=0;i<v;i++)
    {
        state[i]=unvisited;
    }
    printf("enter the start point : ");
    scanf("%d",&start);
    DFS(v,start);
}
void DFS(int v,int start)
{
    int top_vert;

    printf("DFS traversal : ");

    printf("%d ",start);
    state[start]=visited;
    push(start);
    while(!isempty())
    {
        top_vert=peek();

        for(i=0;i<v;i++)
        {

            if(adj[top_vert][i]==1  && state[i]!=visited)
            {
                push(i);
                printf("%d ",i);
                state[i]=visited;
                break;
            }
        }
        if(i==v)
        {
            pop();
        }


    }

}

int main()
{
    int n;
    printf("Enter how many vertices : ");
    scanf("%d",&n);
    creategraph(n);
    DFS_traversal(n);
}

/*
0 1 0 1 0
1 0 1 1 0
0 1 0 0 1
1 1 0 0 1
0 0 1 1 0
*/
