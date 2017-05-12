#include <cstdio>
#include <cstring>
#define maxn 10001000
struct node
{
    int next[26];
    int idx;
    void init()
    {
        idx=0;
        memset(next,-1,sizeof(next));
    }
}t[maxn];
int cur=1;
void insert(char *s,int n)
{
    int p=0;
    for(int i=0;i<n;i++)
    {
        int x=s[i]-'a';
        if(t[p].next[x]==-1)
        {
            t[cur].init();
            t[p].next[x]=cur++;
        }
        p=t[p].next[x];
        t[p].idx++;
    }
}
void q(char *s)
{
    int i=0,p=0;
    while(s[i])
    {
        int x=s[i]-'a';
        if(t[p].next[x]==-1)
        {
            printf("0\n");
            return;
        }
        i++;
        p=t[p].next[x];
    }
    printf("%d\n",t[p].idx);
}
int main()
{
    t[0].init();
    char s[20];
    while(gets(s)!=NULL)
    {
        int len=strlen(s);
        if(len==0)
            break;
        insert(s,len);
    }
    while(~scanf("%s",&s))
    {
        q(s);
    }
    return 0;
}
