#include<stdio.h>
#include<string.h>
char map[100][100];
int n,m,cout,vis[100];

void dfs(int x,int cur)
{
    if(x<n)
    {
        if(cur==m-1)
        {
            cout++;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                int flag=1;
                if(map[x][i]=='#')
                {
                    for(int j=0; j<i; j++)
                    {
                        if(vis[j]!=-1)
                        {
                            flag==0;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                        vis[x]=i;
                        dfs(x+1,cur+1);
                        vis[x]=-1;
                    }
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==-1&&m==-1)
            break;
        cout=0;
        memset(vis,-1,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
        }
        dfs(0,0);
        printf("%d\n",cout);
    }
    return 0;
}
