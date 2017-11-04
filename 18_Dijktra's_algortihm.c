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
void dijkstra(int G[MAX][MAX],int n,int startnode)
{

    int cost[MAX][MAX],distance[MAX],path[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(G[i][j]==0)
            {
                cost[i][j]=infinity;
            }
            else
                cost[i][j]=G[i][j];
        }

    }
    distance[startnode]=0;
    path[startnode]=startnode;

    for(i=0; i<n; i++)
    {
        if(i!=startnode)
        {

            distance[i]=infinity;
            path[i]=-1;
        }
    }

    for(i=0; i<n; i++)
    {
        visited[i]=0;
    }
    /*printf(" visited distance path : ");
    for(i=0; i<n; i++)
    {
       printf("\n %d %d %d ",visited[i],distance[i],path[i]);
    }*/

    count=0;

    while(count<n-1)
    {
        mindistance=infinity;

        for(i=0; i<n; i++)
        {
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
                //printf("\n dis %d = %d ",i,distance[i]);
            }
        }

        visited[nextnode]=1;

        for(i=0; i<n; i++)
        {
            if(!visited[i])
            {
                //printf("traverse= %d",i);
                if(distance[i]>mindistance+cost[nextnode][i])
                {
                    //printf("distance = %d",distance[i]);
                    distance[i]=mindistance+cost[nextnode][i];
                    //printf("distance = %d",distance[i]);
                    path[i]=nextnode;
                }
            }
        }
        count++;

    }

    for(i=0; i<n; i++)
    {
        if(i!=startnode)
        {
            printf("\n\nDistance of node %d from node %d (starting node) is %d",i,startnode,distance[i]);
            printf("\nPath : %d",i);
            j=i;
            do
            {
                j=path[j];
                printf(" <- %d",j);
            }
            while(j!=startnode);
        }
    }

printf("\n");

}
/*
0 1 1
1 0 1
1 1 0

0 1 0 1 0
1 0 1 1 0
0 1 0 0 1
1 1 0 0 1
0 0 1 1 0
*/
