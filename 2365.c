#include<stdio.h>
int main()
{
    int a,b,c,sum;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        sum=a+b+c;
        if(sum<0)
        printf("%d\n",-sum);
        else
        printf("%d\n",sum);

    }
}
