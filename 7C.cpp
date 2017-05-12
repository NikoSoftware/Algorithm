#include<stdio.h>
#include<string.h>
char map[8][8];
int vis[8];
int n,m,k,c;

void dfs(int begin ,int num)
{
    for(int j=0;j<n;j++)
	{
		if(map[begin][j]=='#' && vis[j]==0)
		{
			if(num==1)
				c++;
			else
			{
				vis[j]=1;
				for(int h=begin+1;h<n-num+2;h++)
					dfs(h,num-1);
				vis[j]=0;
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
        for(int i=0;i<n;i++)
        scanf("%s",map[i]);
        for(int i=0;i<m;i++)
        vis[i]=0;
        for(int i=0;i<n-m;i++)
        {
            dfs(i,m);
        }
    }
    return 0;
}
