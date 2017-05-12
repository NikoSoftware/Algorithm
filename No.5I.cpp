#include<stdio.h>
#include<string.h>
#define N 205
bool mark[N][N];
char s[2*N],s1[N],s2[N];
int len,len1,len2,res;
void DP(int i,int j,int k)
{
    if (k>=len) {res=1;return ;}
    if (mark[i][j]) return ;
    else mark[i][j]=1;
    if (i>len1 || j>len2) return;
    if (s1[i]!=s[k] && s2[j]!=s[k])  return ;
    if (i<len1 && s1[i]==s[k] && res==0) DP(i+1,j,k+1);
    if (j<len2 && s2[j]==s[k] && res==0) DP(i,j+1,k+1);
}
int main()
{
    int T,t;
    scanf("%d",&T);
    for (t=1;t<=T;++t)
    {
        scanf("%s%s%s",s1,s2,s);
        len=strlen(s);
        len1=strlen(s1);
        len2=strlen(s2);
        memset(mark,0,sizeof(mark));
        res=0;
        DP(0,0,0);
        if (res) printf("Data set %d: yes/n",t);
        else printf("Data set %d: no/n",t);
    }
}
