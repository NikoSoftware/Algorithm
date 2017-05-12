#include<stdio.h>
int main()
{
    int a[10][10]={1},i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
          for(i=0;i<n;i++)
        {
            printf("%d",a[0][i]);
            for(j=1;j<n;j++)
            {
        printf(" %d",a[j][i]);
    }
    printf("\n");
        }
    }
    return 0;
}
