#include<stdio.h>
void insertionsort(int *,int);
int main()
{
    int i,n,a[100];
    printf("enter how many elements : ");
    scanf("%d",&n);
    printf("\ninput array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\ninputed array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    insertionsort(a,n);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void insertionsort(int a[], int n)
{
    int i,j,val;
    for(i=1;i<n;i++)
    {
        val=a[i];
        for(j=i-1; j>=0 && val<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=val;
    }
}
