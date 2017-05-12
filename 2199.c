#include<stdio.h>
int main()
{
    int a,b,c,sum;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        sum=0;
        sum=a+b+c;
        printf("%d\n",sum);
    }
}
