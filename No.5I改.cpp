#include<stdio.h>
#include<string.h>

bool vis[1000][1000];
char s1[1000],s2[1000],s[2000];
int len,len1,len2,count;

void dp(int i,int j,int k)
{
    if(k>=len)
    {
        count=1;
        return ;
    }
    if(vis[i][j])
        return ;
    else
        vis[i][j]=1;
    if(i>len1||j>len2)
        return;
        if(s1[i]!=s[k]&&s2[j]!=s[k])
        return ;
    if(i<=len1&&s1[i]==s[k]&&count==0)
    {
        dp(i+1,j,k+1);
    }
    if(j<=len2&&s2[j]==s[k]&&count==0)
    {
        dp(i,j+1,k+1);
    }

}


int main()
{
    int k=0,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s%s%s",s1,s2,s);
            len=strlen(s);
            len1=strlen(s1);
            len2=strlen(s2);
            memset(vis,0,sizeof(vis));
            count=0;
            dp(0,0,0);
            if(count)
                printf("Data set %d: yes\n",i+1);
            else
                printf("Data set %d: no\n",i+1);
        }
    }
    return 0;
}
