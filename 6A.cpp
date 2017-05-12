#include<stdio.h>
#include<string.h>
int main()
{
    char a[100][100];
    int k,n,m,i,b[100],x,j;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&n,&m);
        for(j=0;j<n;j++)
        {
            scanf("%s",a[j]);
        }
        for(j=0;j<m;j++)
        {
            scanf("%d",&x);
            printf("%s\n",a[x-1]);
        }
    }
    return 0;
}
