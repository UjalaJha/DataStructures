#include<stdio.h>
void selectionsort(int *,int);
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
    selectionsort(a,n);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void selectionsort(int a[], int n)
{
    int min,i,j,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
