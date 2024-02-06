#include<stdio.h>
void main()
{
    int n,i,j;
    printf("enter the order  of matrix");
    scanf("%d",&n);
    int a[n][n];
    printf("enter the element of matrix");
    for(i=0;i<n;i++)
       {
        for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
       }
printf("\n dignol element of matrix are ");
for(i=0;i<n;i++)
{
    printf("%d ",a[i][i]);
}
}                  