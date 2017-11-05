#include<stdio.h>
void shellsort(int *,int,int,int *);
int main()
{
    int i,n,a[100];
    printf("enter how many elements : ");
    scanf("%d",&n);
    printf("\ninput array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\ninputed array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    int incarray[]= {1,2,4};
    int inc=3;
    shellsort(a,n,inc,incarray);
    printf("\nSorted array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}
void shellsort(int a[], int n,int inc,int incarray[])
{
    int i,j,val,k,span;
    for(k=inc-1; k>=0; k--)
    {
        span=incarray[k];

        for(i=span; i<n; i++)
        {
            val=a[i];
            for(j=i-span; j>=0 && val<a[j]; j=j-span)
            {
                a[j+span]=a[j];
            }
            a[j+span]=val;
        }
    }

}

