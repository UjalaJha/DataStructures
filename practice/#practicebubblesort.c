#include<stdio.h>
void bubblesort(int *,int);
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
    bubblesort(a,n);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void bubblesort(int a[],int n)
{
    int j,i,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }

    }

}
