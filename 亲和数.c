#include<stdio.h>
int main()
{
    int T,i,j,a,b,suma,sumb;
    while(scanf("%d",&T)!=EOF)
    {
        for(i=0;i<T;i++)
        {
            scanf("%d%d",&a,&b);
            suma=sumb=0;
            for(j=1;j<a;j++)
            if(a%j==0)
            suma+=j;
            for(j=1;j<b;j++)
            if(b%j==0)
            sumb+=j;
            if(suma==b&&sumb==a)
            printf("YES\n");
            else
            printf("NO\n");
        }
    }
}
