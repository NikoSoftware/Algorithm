#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    for(i=100;i<1000;i++)
    {
        n=pow(i/100,3.0)+pow((i%100)/10,3.0)+pow((i%100)%10,3.0);
        if(i==n)
        printf("%d  ",i);
    }
}
