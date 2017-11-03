#include<stdio.h>
void shellsort(int *,int, int *, int);
int main()
{
    int i,n,arr[100];
    printf("enter how many number : ");
    scanf("%d",&n);
    printf("enter number : ");

    for(i=0; i<n; i++)
    {

        scanf("%d",&arr[i]);
    }

    int incarray[]= {1,2,4};
    int inc=3;

    shellsort(arr,n,incarray,inc);

    printf("Sorted array is : ");
    for(i=0; i<n; i++)
    {

        printf("\t %d",arr[i]);
    }
}
shellsort(int a[],int n, int incarray[], int inc)
{
    int i,j,k,temp,span;
    for(i=inc-1; i>=0; i--)
    {
        span=incarray[i];
        for(j=span; j<n; j++)
        {
            temp=a[j];
            for(k=j-span; k>=0&&temp<a[k]; k=k-span)
            {
                a[k+span]=a[k];
            }
            a[k+span]=temp;
        }
    }
}
