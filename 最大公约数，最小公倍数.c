#include<windows.h>
int main()
{
int a,b,remainder,c,same,z;
scanf("%d%d",&a,&b);
if(a<=0,b<=0)
return 0;
if(a<b)
{
c=a;a=b;b=c;
}
z=b;
remainder=a%b;
if(remainder==0)
{
printf("%d %d",b,a);
}
else
if(remainder!=0)
{
while(remainder!=0)
{  same=remainder;
    //这一步用的很巧
remainder=b%remainder;
}
printf("%d ",same);
printf("%d",a*z/same);
}
return 0;
}
