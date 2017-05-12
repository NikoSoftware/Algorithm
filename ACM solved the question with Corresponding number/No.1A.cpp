#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int data[15],n,count;

void dfs(int x)
{
    if(x==n)
    {
        count++;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            int y=i;
            int flag=1;
            for(int j=0; j<x; j++)
            {
                if(data[j]==y||data[j]-j==y-x||data[j]+j==y+x)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                data[x]=i;
                dfs(x+1);
            }
        }

    }

}
int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        memset(data,0,sizeof(data));
        count=0;
        dfs(0);
        printf("%d\n\n",count);
    }

    return 0;
}
