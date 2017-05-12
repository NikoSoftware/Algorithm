#include<stdio.h>
int main()
{
    int n,m,a,b,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&a,&m);
            for(j=1; j<=m; j++)
            {
                scanf("%d",&b);
                sum+=b;
                if((sum-(j-1)*a)>=0)
                {


                }
            }
        }

    }
    return 0;
}
