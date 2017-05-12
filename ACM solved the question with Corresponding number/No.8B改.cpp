#include<stdio.h>
#include<string.h>
int cur=0;

struct Node
{
    int next[26];
    char data[100];
    void init()
    {
        memset(next,-1,sizeof(next));
    }
}t[10000];

void insert(char* s1,char *s2)
{
    int p=0;
    for(int i=0;i<strlen(s2);i++)
    {
        int x=s2[i]-'a';

        if(t[p].next[x]==-1)
        {   puts("fsda");
            t[cur].init();
            t[p].next[x]=cur++;
        }
        p=t[p].next[x];
    }
    printf("%d",cur);
    strcpy(t[p].data,s1);
}


int main()
{
    char a[1000],s1[100],s2[100];
    t[cur].init();
    while(gets(a)!=NULL)
    {
        int i=0;
        while(a[i]!=' ')
        {
            s1[i]=a[i++];
        }
        s1[i++]='\0';
        strcpy(s2,a+i);

        insert(s1,s2);
        puts("fsda");

    }
    //for(int i=0;i<cur;i++)
    printf("%s",t[cur-1].data);




    return 0;
}
