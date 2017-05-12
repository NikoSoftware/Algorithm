#include<stdio.h>
#include<string.h>

int cur=0;

struct Node
{
    int next[26];
    char data[20];
    void init()
    {
        memset(next,-1,sizeof(next));
    }
}t[1000000];

void insert(char* s1,char *s2)
{
    int p=0;
    for(int i=0; i<strlen(s2); i++)
    {
        int x=s2[i]-'a';
        if(t[p].next[x]==-1)
        {
            t[cur].init();
            t[p].next[x]=cur++;
        }
        p=t[p].next[x];
    }
    strcpy(t[p].data,s1);
}
void q(char* a)
{
    int i=0,p=0;
    while(a[i])
    {
        int x=a[i]-'a';
        if(t[p].next[x]==-1)
        {
            printf("eh\n");
            return;
        }
        i++;
        p=t[p].next[x];
    }
    printf("%s\n",t[p].data);
}

int main()
{
    char a[100],s1[20],s2[20];
    t[cur].init();

    while(gets(a)!=NULL)
    {
        if(strlen(a)==0)
            break;
        int i=0;
        while(a[i]!=' ')
        {
            s1[i++]=a[i];
        }
        s1[i++]='\0';
        int cnt=0;
        while(a[i]!='\0')
        {
            s2[cnt++]=a[i++];
        }
        s2[cnt]='\0';
        //printf("%s ",s2);
        //puts("fadsfa");
        insert(s1,s2);
    }
    //puts("fdsa");
    //for(int i=0;i<cur;i++)
    //printf("%c ",t[i].id);
    while(scanf("%s",a)!=EOF)
    {
        q(a);
    }
    return 0;
}
