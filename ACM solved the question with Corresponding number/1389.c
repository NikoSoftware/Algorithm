#include<stdio.h>
int main()
{
    int a[100],n,m,j,i,sum;
    while(scanf("%d",&n)!=EOF)
    {

        for(i=0; i<n; i++)
        {
            sum=0;
            scanf("%d",&m);
            for(j=0; j<m; j++)
            {
                scanf("%d",&a[j]);
                sum+=a[j];
            }
            printf("%d\n\n",sum);
        }
    }
    return 0;
}
