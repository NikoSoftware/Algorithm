#include<stdio.h>
#include<string.h>
int n,a[100],vis[100],b[100];
void dfs(int cur,int k)
{
    int i,j;
    if(cur>n)
        return;
    if(k==6)
    {
        printf("%d",k);
        for(j=0;j<n;j++)
        {
            //printf("%d %d\n",b[j],a[j]);
            //if(b[j]==1)
                printf("%d ",b[j]);
        }
        printf("\n");
        getchar();
        return ;
    }
    else
    for(i=cur;i<n;i++)
    {
        b[i]=1;
        dfs(cur+1,k+1);
        b[i]=0;
        dfs(cur+1,k);
    }
}
int main()
{
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    memset(b,0,sizeof(b));

    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(0,0);
    return 0;
}
