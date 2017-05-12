#include<stdio.h>
#include<string.h>
bool a[1000],vis[1000];
int map[1000],z=1,n;
void saixuan()
{
    int i,j;
    for(i=2;i<1000;i++)
    {
        if(!a[i])
        {
        for(j=i+i;j<1000;j+=i)
        {
            a[j]=1;
        }
        }
    }
}
void dfs(int cur)
{
    int i,j;
        if(z==n)
        {
            if(a[map[z-1]+1]==0)
            {
                map[0]=1;
                for(i=0;i<n;i++)
                printf(" %d",map[i]);
                printf("\n");
            }
        }
    else for(i=2;i<=n;i++)
    {
        if(vis[i])
        continue;
        if(a[cur+i]==0)
        {
            vis[i]=1;
            map[z++]=i;
            dfs(i);
            map[z--]=0;
            vis[i]=0;
        }
    }

}
int main()
{
    int i;
    scanf("%d",&n);
    saixuan();
    vis[1]=1;
    dfs(1);

    return 0;
}
