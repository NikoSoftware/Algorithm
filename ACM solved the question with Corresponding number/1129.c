#include<stdio.h>
#include<string.h>
int x[4],ans[4],vis[4],u;
void dg(int cou)
{
    int i;
    if(cou==4)
    {
        if(u!=ans[0])
            printf("\n");
        for(i=0; i<4; i++)
            printf("%d",ans[i]);
        u=ans[0];
        printf(" ");
        return;
        for(i=0; i<4; i++)
        {
            if(vis[i]==1)
                continue;
            ans[cou]=x[i];
            vis[i]=1;
            dg(cou+1);
            vis[i]=0;
        }
    }
}
    int main()
    {
        int t,i;
        scanf("%d",&t);
        while(t--)
        {
            memset(vis,0,sizeof(vis));
            for(i=0; i<4; i++)
                scanf("%d",&x[i]);
            u=x[0];
            dg(0);
        }
    }
