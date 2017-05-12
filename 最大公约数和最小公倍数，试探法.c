#include<stdio.h>
int main()
{
    int a,b,i,c;
    scanf("%d%d",&a,&b);
    if(a>b)
    c=b;
    else
    c=a;
    for(i=c;i>1;i--)
    {
    if(a%i==0&&b%i==0)
    break;
}
printf("%d %d",i,a*b/i);

}
