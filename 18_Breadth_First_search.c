#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define unvisited 1
#define waiting 2
#define visited 3

int adj[MAX][MAX];
int state[MAX];
void create_graph(int n);
void BFS_Traversal(int n);
void BFS(int start_vertex, int n);

int queue[MAX], f = -1,r = -1;
void insert_queue(int vertex);
int delete_queue();
int isempty();




void main()
{
    int no_of_vertices;
    printf("enter no of vertices : ");
    scanf("%d",&no_of_vertices);
    create_graph(no_of_vertices);
    BFS_traversal(no_of_vertices);
}
void insert_queue(int vertex)
{
    if(r==MAX-1)
    {
        printf("overflow");
        return;
    }
    if(f==-1)
        f=r=0;
    else
        r=r+1;

    queue[r]=vertex;
}
int delete_queue()
{
    if(f == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int vertex=queue[f];
    if(f==r)
        f=r=-1;
    else
        f++;
    return vertex;
}
int isempty()
{
    if(f == -1)
        return 1;
    else
        return 0;
}
void BFS_traversal(int n)
{
    int start_vertex, v;

    for(v=0; v<n; v++)
    {
        state[v]=unvisited;
    }
    printf("Enter the start vertex for BFS : ");
    scanf("%d",&start_vertex);
    BFS(start_vertex, n);

}
void BFS(int v, int n)
{
    int i;

    insert_queue(v);
    state[v] = waiting;

    printf("\nBFS Traversal : ");
    while(!isempty())
    {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = visited;

        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == unvisited)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
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

