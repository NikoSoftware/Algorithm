#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,f[30000];
    memset(f,0,sizeof(f));
    scanf("%d",&n);
    f[0]=1;
    int s,m=10000;
    for(i=2;i<=n;i++)
    {
        int c=0;
        for(j=0;j<m;j++)
        {
            s=f[j]*i+c;
            f[j]=s%10;
            c=s/10;
        }
    }
    for(j=m-1;j>=0;j--)
    if(f[j])
    break;
    for(i=j;i>=0;i--)
    printf("%d",f[i]);
    return 0;
}
