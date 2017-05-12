#include<stdio.h>
int main()
{
    int n,m,z,r;
    while(1)
    {
        z=0;
        scanf("%d",&n);
        if(n==0)
        break;
        while(n--)
        {
            scanf("%d",&m);
            z+=m/100;
            r=m%100;
            z+=r/50;
            r=r%50;
            z+=r/10;
            r=r%10;
            z+=r/5;
            r=r%5;
            z+=r/2;
            z+=r%2;
        }
        printf("%d\n",z);
    }
}
