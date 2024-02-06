#include<stdio.h>
int main()
{
    int c1,r1,c2,r2,m1[10][10],m2[10][10],m3[10][10],k,i,j;
    printf("column of matris 1=");
    scanf("%d",&c1);
    printf("row of matris 1=");
    scanf("%d",&r1);
    printf("column of matris 2=");
    scanf("%d",&c2);
    printf("row of matris 2=");
    scanf("%d",&r2);
    printf("1st matrix");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",m1[i][j]);

        }
    }
    printf("2nd matrix");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",m2[i][j]);

        }
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            int s=0;
            for(k=0;k<c1;k++)
            {
                s=s+m1[i][k]*m2[k][j];
            }
            m3[i][j]=s;
        }
    }
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",m2[i][j]);

        }
        printf("\n");
    }
}