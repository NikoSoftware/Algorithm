#include<stdio.h>
int map[100],vis[100],a[10]={1,8,4,3,5,2};
void dfs(int t,int n)
{
    if(t>=0)
    {
    if(t==0)
    {
        for(int i=0;i<n;i++)
        printf("%d ",map[i]);
        printf("\n");
    }
    else
    for(int i=n;i<6;i++)
    {
        if(t>=a[i]&&vis[i]!=1)
        {
            t=t-a[i];
            vis[i]=1;
            map[n]=a[i];
            //printf("i:%d t:%d",i,t);
           // getchar();
            dfs(t,n+1);

            t=t+a[i];
           // n=n-1;
            vis[i]=0;
        }
    }
    }
}
int main()
{
    int T=10;
    dfs(10,0);
    return 0;
}
