#include<stdio.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
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

    quicksort(arr,0,n-1);

    printf("Sorted array is : ");

    for(i=0; i<n; i++)
    {

        printf("\t %d",arr[i]);
    }
}
quicksort(int a[],int lb,int ub)
{
    if(lb>=ub)
        return;
    int pivot=partition(a,lb,ub);
    quicksort(a,lb,pivot-1);
    quicksort(a,pivot+1,ub);
}
int partition(int a[],int lb,int ub)
{
    int i,temp;
    int pivot=a[ub];
    int pindex=lb;

    for(i=lb; i<ub; i++)
    {
        if(a[i]<=pivot)
        {
            //swap(a[i],a[pindex]);
            temp=a[i];
            a[i]=a[pindex];
            a[pindex]=temp;
            pindex++;
        }
    }
    //swap(a[pindex],a[ub]);
    temp=a[ub];
    a[ub]=a[pindex];
    a[pindex]=temp;

    return pindex;

}

