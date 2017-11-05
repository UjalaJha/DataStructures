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
radixsort(int a[],int n)
{
    int m=getmax(a,n);
    int i,exp=1;
    for(i=0;m/exp>0;exp=exp*10)
    {
        countsort(a,n,exp);
    }

}
countsort(int a[],int n,int exp)
{
    int output[n],i;
    int count[10]={0};
    for(i=0;i<n;i++)
    {
        count[((a[i]/exp)%10)]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[count[((a[i]/exp)%10)]-1]=a[i];
        count[((a[i]/exp)%10)]--;
    }
     for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
