#include<stdio.h>
int main()
{
    float x,y;
    scanf("%f",&x);
    if(x<1)
    printf("%.2f",x);
    else if(x>=1&&x<10)
    printf("%.2f",2*x-1);
    else
    printf("%.2f",3*x-11);
}
