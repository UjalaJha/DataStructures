#include<stdio.h>
void mergesort(int *,int,int);
void merge(int *,int,int,int,int);
#define max 100
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
    mergesort(a,0,n-1);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void mergesort(int a[], int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }

}
void merge(int a[],int l1, int u1,int l2, int u2)
{
    int aux[max],i,k,j;
    i=l1;
    j=l2;
    k=0;
    while(i<=u1 &&j <=u2)
    {
        if(a[i]<=a[j])
        {
            aux[k++]=a[i++];
        }
        else
        {
            aux[k++]=a[j++];
        }

    }
    while(i<=u1)
    {
        aux[k++]=a[i++];
    }
    while(j<=u2)
    {
        aux[k++]=a[j++];
    }
    for(i=l1,j=0; i<=u2; i++,j++)
    {
        a[i]=aux[j];
    }

}
