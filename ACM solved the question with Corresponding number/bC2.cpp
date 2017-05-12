#include<stdio.h>
#include<string.h>
int n,a[100],vis[100];
void dfs(int cur,int k)
{
    int i,j;
    if(k==3)
    {
        for(j=0;j<n;j++)
        if(vis[j]==1)
        printf("%d ",a[j]);
        printf("\n");
        getchar();
    }
    else
    for(i=cur;i<n;i++)
    {
        vis[i]=1;
        dfs(cur+1,k+1);
        vis[i]=0;
        dfs(cur+1,k);
    }
}
int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        dfs(0,0);
    }
    return 0;
}
