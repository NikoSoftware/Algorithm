#include<stdio.h>
#define pi 3.1415926
int main()
{
    int i,n,m;
    double a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&a,&b);
        int k=a/b/2/pi;
        printf("%d\n",i+1);
    }

    return 0;
}
