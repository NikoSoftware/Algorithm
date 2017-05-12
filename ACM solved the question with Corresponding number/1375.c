#include<stdio.h>
int main()
{
    double i;
    double PI=3.14159267,s;
    for(i=1;i<=10;i++)
    {
        s=PI*(i*i);
        if(s>=40&&s<=90)
        printf("r=%.0lf area=%.2lf\n",i,s);
    }
    return 0;
}
