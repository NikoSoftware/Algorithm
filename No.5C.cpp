#include<stdio.h>
#include<string.h>

int a[500005];
bool b[10000000];
void cal()
{
     a[0]=0;
    for(int i=1; i<=500000; i++)
    {
        if(a[i-1]-i>0&&b[a[i-1]-i]!=1)
        {
            a[i]=a[i-1]-i;
            b[a[i]]=1;
        }
        else
        a[i]=a[i-1]+i;
        b[a[i]]=1;
    }
}

int main()
{
    int n;

    cal();
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%d\n",a[n]);

    }

    return 0;
}
