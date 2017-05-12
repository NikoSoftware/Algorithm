#include<stdio.h>
int main()
{
    float a[10],m=0;
    int i;
    for(i=0;i<3;i++)
    scanf("%f",&a[i]);
    for(i=0;i<3;i++)
    {
        if(m<a[i])
        m=a[i];
    }
    printf("%.3f\n%.3f\n",m,m);
    return 0;
}
