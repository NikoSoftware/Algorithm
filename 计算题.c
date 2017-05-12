#include<stdio.h>
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        double sum=1.0;
        for(i=2;i<=n;i++)
        {
            sum-=1.0/(i*i);
        }
        printf("%.6lf\n",sum);
    }
    return 0;
}
