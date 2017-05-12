#include<stdio.h>
#include<string.h>
int vis[2][10000],len1,len2;
char a[10000],b[10000];

int main()
{
    while(scanf("%s%s",a+1,b+1)!=EOF)
    {
        len1=strlen(a+1);
        len2=strlen(b+1);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(a[i]==b[j])
                {
                    vis[i%2][j]=vis[(i-1)%2][j-1]+1;
                }
                else
                vis[i%2][j]=(vis[(i-1)%2][j]>=vis[i%2][j-1]?vis[(i-1)%2][j]:vis[i%2][j-1]);
            }
        }
        printf("%d\n",vis[len1%2][len2]);

    }
    return 0;
}
