#include<stdio.h>
int main()
{
    int i,j,tem,a[30][30],n;
    for(i=0;i<30;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2;i<30;i++)
    {
        for(j=1;j<i;j++)
        {
        a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            printf("%d",a[i][0]);
            for(j=1;j<=i;j++)
            {
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
