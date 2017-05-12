#include<stdio.h>
#include<math.h>
double function1(int x)
{
    return pow(x,2.0)-sin(x);
}
double function2(int x)
{
    return pow(2.0,x)+x;
}
double function3(int x)
{
    return sqrt(x*x+x+1);
}
int main()
{
   int n,x,i;
   double y;
    scanf("%d",&n);
        for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        if(x<-2)
        y=function1(x);
        else if(x<=2)
        y=function2(x);
        else
        y=function3(x);
            printf("%.2lf\n",y);
        }

return 0;
}
