#include<stdio.h>
int count,sum,n,m;
void dfs(int cur,int k)
{
    if(cur==m)
    {
        if(sum==0)
        count++;
    }
    else
    for(int i=k;i<=(n/(m-cur)+1);i++)
    {
        sum=sum-i;
        dfs(cur+1,i);
        sum=sum+i;
    }
}
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&n,&m);
        sum=n;
        count=0;
        dfs(0,0);
        printf("%d\n",count);
    }
    return 0;
}
