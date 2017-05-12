#include<stdio.h>
#include<string.h>

int cur=1;

struct Node
{
    int next[12];
    int id;
    void init()
    {
        memset(next,-1,sizeof(next));
        id=0;
    }
} t[1000000];

int insert(char * data)
{
    int p=0;
    for(int i=0; i<strlen(data); i++)
    {
        int x=data[i]-'0';
        if(t[p].next[x]==-1)
        {
            t[cur].init();
            t[p].next[x]=cur++;
        }
        p=t[p].next[x];
        if(t[p].id!=0)
        {
            return 1;
        }
    }

    t[p].id=1;
    return 0;
}

int main()
{
    int k,n;
    char data[12];
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        cur=1;
        int flag=0;
        t[0].init();
        scanf("%d",&n);
        for(int j=0; j<n; j++)
        {
            scanf("%s",data);
            flag+=insert(data);
            //printf("%d\n",flag);
        }
        if(flag!=0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
