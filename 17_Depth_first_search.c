#include<stdio.h>
#define MAX 100
#define unvisited 1
#define visited 2
int no_of_vertices;
int state[MAX];
void create_graph(int n);
void DFS_traversal(int n);
void DFS(int start_vertex, int n);
int adj[MAX][MAX];
int stack[MAX], top = -1;
void push(int vertex);
int pop();
int isEmpty_stack();
int peek();

void main()
{
    printf("enter no of vertices : ");
    scanf("%d",&no_of_vertices);
    create_graph(no_of_vertices);
    DFS_traversal(no_of_vertices);
}
void DFS_traversal(int n)
{
    int start_vertex, v;

    for(v=0; v<n; v++)
    {
        state[v]=unvisited;
    }
    printf("Enter the start vertex for DFS : ");
    scanf("%d",&start_vertex);
    DFS(start_vertex, n);

}
void DFS(int start_vertex,int n)
{
    int i, top_vertex, univisted_neighbor;

    printf("\nDFS Traversal : ");
    push(start_vertex);
    state[start_vertex]=visited;
    printf("%d ",start_vertex);

    while(!isempty())
    {
        top_vertex=peek();

        for(i=0; i<n; i++)
        {

            if(adj[top_vertex][i]==1 && state[i]==unvisited)
            {
                push(i);
                printf("%d ",i);
                state[i]=visited;
                break;
            }

        }
        if(i==n) //if all adjacent node are visited
        {
            pop();
        }


    }
}
int isempty()
{
    if (top==-1)
        return 1;
    else
        return 0;
}
int peek()
{
    if(top == -1)
    {
        printf("\nStack Empty!!!");
        return;
    }
    return stack[top];
}
void push(int vertex)
{
    if(top == MAX-1)
    {
        printf("\nStack Overflow !!!");
        return;
    }

    stack[++top]=vertex;
}
int pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow !!!");
        return;
    }
    int vertex=stack[--top];
    return vertex;
}
void create_graph(int n)
{
    int i,j;
    printf("enter the adjacency matrix : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&adj[i][j]);
        }
        printf("\n");
    }
    printf("the adjacency matrix is : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\t %d",adj[i][j]);
        }
        printf("\n");
    }

}
/*
0 1 0 1 0
1 0 1 1 0
0 1 0 0 1
1 1 0 0 1
0 0 1 1 0
*/
