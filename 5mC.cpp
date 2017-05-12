#include<stdio.h>
#include<string.h>
bool vis[1000];
char map[1000][1000];
int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<n;j++)
            {
                if(map[i][j]=='.')
                vis=1;
            }
        }
    }
    return 0;
}
