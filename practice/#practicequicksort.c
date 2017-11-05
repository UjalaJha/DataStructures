#include<stdio.h>
void quicksort(int *,int, int);
int partition(int *,int, int);
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
    quicksort(a,0,n-1);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void quicksort(int a[], int i,int j)
{
    if(i>=j)
        return;
    else
    {
        int pivot=partition(a,i,j);
        quicksort(a,i,pivot-1);
        quicksort(a,pivot+1,j);
    }


}
int partition(int a[],int i,int j)
{
    int k,temp;
    int pivot=a[j];
    int pindex=i;

    for(k=i;k<j;k++)
    {
        if(a[k]<=pivot)
        {
            temp=a[k];
            a[k]=a[pindex];
            a[pindex]=temp;
            pindex=pindex+1;
        }
    }
    temp=a[j];
    a[j]=a[pindex];
    a[pindex]=temp;

    return pindex;
}

