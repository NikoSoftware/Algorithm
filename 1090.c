#include<stdio.h>
int main()
{
    int i,j,n,m,sum;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        sum=3;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            sum=(sum-1)*2;
        }
        printf("%d\n",sum);
    }
}
