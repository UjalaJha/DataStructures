
#include<stdio.h>
void bubblesort(int *,int);
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

    bubblesort(arr,n);

    printf("Sorted array is : ");

    for(i=0; i<n; i++)
    {

        printf("\t %d",arr[i]);
    }
}
bubblesort(int arr[],int n)
{
    int i,j,temp,exchange=1;
    for(i=0; i<n-1&&exchange; i++)
    {
        exchange=0;
        for(j=0; j<n-i-1; j++)
        {

            if(arr[j]>arr[j+1])
            {
                exchange=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}
