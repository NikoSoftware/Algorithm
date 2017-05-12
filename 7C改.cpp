#include<stdio.h>
char map[1000][1000];
int vis[1000];
int n,m,k,c;

void dfs(int begin,int num)
{
    for(int i=0; i<n; i++)
    {
        if(map[begin][i]=='#'&&vis[i]==0)
        {
            if(num==1)
            {
                c++;
            }
            else
            {
                vis[i]=1;
                for(int h=begin+1;h<n-num+2;h++)
                dfs(h,num-1);
                vis[i]=0;
            }
        }
    }

}


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        c=0;
        if(n==-1&&m==-1)
            return 0;
        for(int i=0; i<n; i++)
            scanf("%s",map[i]);
        for(int i=0; i<m; i++)
            vis[i]=0;
        for(int i=0; i<=n-m; i++)
        {
            dfs(i,m);
        }
        printf("%d\n",c);
    }
    return 0;
}
