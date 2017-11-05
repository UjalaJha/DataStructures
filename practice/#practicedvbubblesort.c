#include<stdio.h>
void advbubblesort(int *,int);
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
    advbubblesort(a,n);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void advbubblesort(int a[],int n)
{
    int j,i,temp,flag=1;
    for(i=0;i<n-1 && flag ;i++)
    {
        flag=0;

        for(j=0;j<n-i-1;j++)
        {

            if(a[j]>a[j+1])
            {
                flag=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }

    }

}

