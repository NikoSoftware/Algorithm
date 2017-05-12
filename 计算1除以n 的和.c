#include<stdio.h>
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        double sum=0.0;
        for(i=1;i<=n;i++)
        {
            sum+=1.0/i;
        }
        printf("%.6lf\n",sum);
    }
}
