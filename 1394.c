#include<stdio.h>
#include<string.h>
int main()
{
    int a[120][120],i,j,n;
    a[0][0]=1;
    for(i=0;i<100;i++)
    a[i+1][0]=a[i][0]+i+1;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        a[i][j+1]=a[i][j]+j+i+2;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
         printf("%d ",a[i][j]);
        printf("%d",a[i][n-i-1]);
        printf("\n");
    }
}
