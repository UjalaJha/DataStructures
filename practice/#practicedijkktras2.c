#include<stdio.h>
#define MAX 100
#define infinity 999
int n,i,j;
int G[MAX][MAX];
void dijkstra(int G[MAX][MAX],int n,int startnode);
int main()
{
    int u;

    printf("\n Enter no of vertices : ");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    printf("\n Entered adjacency matrix : \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("\n ");

    printf("Enter the starting node : ");
    scanf("%d",&u);
    dijkstra(G,n,u);
}
void dijkstra(int adj[MAX][MAX],int n,int startnode)
{
    int cost[MAX][MAX];
    int path[n];
    int distance[n];
    int visited[n];
    path[startnode]=startnode;
    distance[startnode]=0;
    int c;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(i!=startnode)
        {
            path[i]=-1;
            distance[i]=infinity;
        }
    }
     for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(adj[i][j]==0)
            {
                cost[i][j]=infinity;
            }
            else
                cost[i][j]=adj[i][j];
        }

    }

     c=0;
     int nextnode;
    while(c<n-1)
    {
        int mindistance=infinity;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=i;

        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(distance[i]>mindistance+cost[startnode][i])
                {
                    distance[i]=mindistance+cost[startnode][i];
                    path[i]=nextnode;
                }
            }
        }


        c++;

    }


  for(i=0;i<n;i++)
    {
        if(i!=startnode)
        {
              printf("\n\n distance of %d from %d(startnode) is %d",i,startnode,distance[i]);
              printf("\npath is %d",i);
              j=i;
              do
              {
                  j=path[j];
                  printf("<- %d",j);
              }
              while(j!=startnode);
        }

    }




}
