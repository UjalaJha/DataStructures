#include<stdio.h>
void selectionsort(int *,int);
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

    selectionsort(arr,n);

    printf("Sorted array is : ");

    for(i=0; i<n; i++)
    {

        printf("\t %d",arr[i]);
    }
}
selectionsort(int arr[],int n)
{
    int i,j,min_idx,temp;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }
}
