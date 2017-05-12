#include<stdio.h>
long long z,i,j,a,b,sum,jian,shen;
double chu;
int main()
{

    while(scanf("%d",&z)!=EOF)
    {
        for(i=0;i<z;i++)
        {
        scanf("%lld%lld",&a,&b);
        sum=a+b;
        jian=a-b;
        shen=a*b;
        chu=a*1.0/b;
        printf("%lld %lld %lld %.7lf\n",sum,jian,shen,chu);
        }
    }
}
