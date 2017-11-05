#include<stdio.h>
#define MS 100
#define visited 1
#define unvisited 0
#define waiting 2
int state[MS];
int adj[MS][MS];
int queue[MS];
int f=-1,r=-1;
int i,j;
void insertqueue(int vertex)
{

    if(f==-1&&r==-1)
    {
        f=r=0;
    }
    else
        r++;
    queue[r]=vertex;
}
int deletequeue()
{
    int vertex=queue[f];
    if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
    return vertex;
}
int isempty()
{
    if(f==-1)
        return 1;
    return 0;
}
void creategraph(int v)
{
    printf("input adj matrix : \n");
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("inputed adj matrix : \n");
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}
void BFS_traversal(int v)
{
    int start;
    for(i=0; i<v; i++)
    {
        state[i]=unvisited;
    }
    printf("enter the start point : ");
    scanf("%d",&start);
    BFS(v,start);
}
void BFS(int nv,int start)
{
    int i,v;

    printf("BFS traversal : ");

    state[start]=waiting;
    insertqueue(start);

    while(!isempty())
    {
        v=deletequeue();
        printf("%d ",v);
        state[v]=visited;

        for(i=0; i<nv; i++)
        {
            if(adj[v][i]==1  && state[i]==unvisited)
            {
                insertqueue(i);
                state[i]=waiting;
            }
        }

    }

}

int main()
{
    int n;
    printf("Enter how many vertices : ");
    scanf("%d",&n);
    creategraph(n);
    BFS_traversal(n);
}
