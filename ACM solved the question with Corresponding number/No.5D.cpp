#include<stdio.h>
int a[100];

void cal()
{
    a[1]=2;
    a[2]=3;
    for(int i=3;i<50;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
}

int main()
{
    int n;
    cal();
    while(scanf("%d",&n)!=EOF)
    {
        int k;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            printf("Scenario #%d:\n%d\n\n",i+1,a[k]);
        }
    }
    return 0;
}
