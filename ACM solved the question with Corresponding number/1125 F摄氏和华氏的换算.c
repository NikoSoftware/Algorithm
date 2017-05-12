#include<stdio.h>
#include<math.h>
double ctof(int n)
{
    return 32+n*9/5;
}
int main()
{
    int n,F;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>=-100&&n<=150)
       {
           F=ctof(n);
        printf("c=%d->f=%d\n",n,F);
       }
    }
    return 0;
}
