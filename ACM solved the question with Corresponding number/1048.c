#include<stdio.h>
#include<string.h>
int main()
{
    int a[100][100],i,j,n,c,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        c=n/2;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            sum+=a[i][i]+a[i][n-i-1];
        }
        if(n%2!=0)
        sum-=a[c][c];
        printf("%d\n",sum);
    }
}
