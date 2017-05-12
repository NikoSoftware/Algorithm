#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,dp[105][105],a[105][105];
int to[4][2] = {1,0,-1,0,0,1,0,-1};

int check(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
        return 1;
    return 0;
}

int dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    int ans = 0;
    for(int i = 0; i<4; i++)
    {
        int xx = x+to[i][0];
        int yy = y+to[i][1];
        if(check(xx,yy) || a[xx][yy]>=a[x][y])
            continue;
       ans = max(ans,dfs(xx,yy));
    }
    dp[x][y] = ans+1;
    return dp[x][y];
}

int main()
{
    int i,j,ans = 0;
    scanf("%d%d",&n,&m);
    for(i = 1; i<=n; i++)
        for(j = 1; j<=m; j++)
        {
            scanf("%d",&a[i][j]);
            dp[i][j] = 0;
        }
    for(i = 1; i<=n; i++)
        for(j = 1; j<=m; j++)
        {
            ans = max(ans,dfs(i,j));

        }
    printf("%d\n",ans);

    return 0;
}
