#include<stdio.h>
int main()
{
    int a,b,c,Max;
    scanf("%d%d%d",&a,&b,&c);
    Max=a;
    if(a<b)
    {
    Max=b;
    if(Max>c)
    printf("%d",Max);
    else
    printf("%d",c);
    }
}
