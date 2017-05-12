#include<stdio.h>
#include<math.h>
double function1(int x)
{
    return fabs(x);//¸¡µãÊý

}
double function2(int x)
{
    return pow(x+1,1.0/2);
}
double function3(int x)
{
    return pow(x+2,5.0);
}
double function4(int x)
{
    return 2*x+5;
}
int main()
{
int x;
double ans;
while(scanf("%d",&x)!=EOF)
{
    if(x<0)
ans=function1(x);
else if(x<2)
ans=function2(x);
else if(x<4)
ans=function3(x);
else
ans=function4(x);
printf("%.2lf\n",ans);
}
}














