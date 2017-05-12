#include<stdio.h>
#include<math.h>
int main()
{
    int n,m;
     for(n=100;n<1000;n++)
    {
    m=pow((n/100),3.0)+pow((n%100)/10,3.0)+pow((n%100)%10,3.0);
    if(m==n)
    printf("%d ",m);
    else
    continue;
}
}
