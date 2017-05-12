#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m;
    char a[10000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            int sum=0;
            scanf("%d",&m);
            int b=n,c=0,z,j;
            while(b!=0)
            {
                z=b%2;
                b=b/2;
                a[c++]=z+'0';
            }
            for(j=0;j<c;j++)
            printf("%c",a[j]);
        }

    }

    return 0;
}
