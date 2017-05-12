#include<stdio.h>
int main()
{
    int n,a[100],i,j,m,q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        m=0,q=0;
        for(j=0;j<6;j++)
        scanf("%d",&a[j]);
        a[2]=a[2]+a[5];
        if(a[2]>59)
        {
            a[2]=a[2]-60;
            m=1;
        }
        a[1]=a[4]+a[1]+m;
        if(a[1]>59)
        {
            a[1]=a[1]-60;
            q=1;
        }
        a[0]=a[0]+a[3]+q;
        printf("%d %d %d\n",a[0],a[1],a[2]);
    }
    return 0;
}
