#include<stdio.h>
int main()
{
    int i,j,tem,a[30][30],n,f;
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
        for(i=n-1;i>=0;i--)
        {
            for(f=0;f<n-i-1;f++)
                printf(" ");
            for(j=i;j>0;j--)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
