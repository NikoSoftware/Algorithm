#include<stdio.h>
int main()
{
    int n,i;
    double PI=3.1415,s[100],r[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%lf",&r[i]);
    for(i=0;i<n;i++)
    {
        s[i]=PI*(r[i]*r[i]);
    }
    for(i=0;i<n;i++)
        printf("%.6lf\n",s[i]);
    return 0;
}
