#include<stdio.h>
#include<math.h>
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
        double sum=100.0;
        for(i=1;i<=n-1;i++)
    {
        sum+=100/pow(2.0,i-1);
    }
    printf("%.4lf\n",sum);
}
return 0;
}
