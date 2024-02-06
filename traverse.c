#include<stdio.h>
void treverse(int a[10],int n)
{
    int i,temp;
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
}
int main()
{
    int a[100],i,size;
    printf("enter the size of array");
    scanf("%d",&size);
    printf("enter the element of array");
    for(i=0;i<size;i++)
    scanf("%d",&a[i]);
    treverse(a,size);
    printf("after treversing tha array");
    for(i=0;i<size;i++)
    {
        printf("%d,",a[i]);
    }
    return 0;
}