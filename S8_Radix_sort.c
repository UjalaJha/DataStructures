#include<stdio.h>
void radixsort(int *,int);
void countsort(int *, int, int);
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

    radixsort(arr,n);

    printf("Sorted array is : ");

    for(i=0; i<n; i++)
    {

        printf("\t %d",arr[i]);
    }
}
radixsort(int a[],int n)
{
    int i,exp=1;
    int m=getmax(a,n);

    for( i=0; m/exp>0; exp=exp*10)
    {
        countsort(a,n,exp);

    }
}
int getmax(int a[],int n)
{
    int i, max=a[0];
    for(i=0; i<n; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void countsort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10]={};

    for(i=0;i<n;i++)
    {
        count[(arr[i]/exp)%10]++;
    }

    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}

