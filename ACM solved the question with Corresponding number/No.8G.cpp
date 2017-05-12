#include<stdio.h>
#include<string.h>

int cur=1;
struct Node
{
    int next[26];
    char data[100];
    void init()
    {
        memset(next,-1,sizeof(next));
    }

} t[1000000];
void insert(char* s1,char *s2)
{
    int p=0;//puts("fasf");
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
    // printf("%d\n",cur);

    strcpy(t[p].data,s1);
}

void p(char * s2)
{
    //puts(" ");
    int p=0;
    for(int i=0; i<strlen(s2); i++)
    {
        int x=s2[i]-'a';
        if(t[p].next[x]==-1)
        {
            printf("%s",s2);
            return ;
        }
        p=t[p].next[x];
    }
    if(strlen(t[p].data)!=0)
        printf("%s",t[p].data);
    else
        printf("%s",s2);
}


int main()
{
    char a[3100],s1[3000],s2[3000];
    t[0].init();
    while(scanf("%s",a)!=EOF)
    {
        if(strcmp(a,"START")==0)
            break;
    }
    getchar();
    while(gets(a)!=NULL)
    {
        // puts(a);
        //cur=1;
        if(strcmp(a,"END")==0)
            break;
        int i=0;
        while(a[i]!=' ')
        {
            s1[i++]=a[i];
        }
        //puts("fas");
        s1[i++]='\0';
        strcpy(s2,a+i);
        insert(s1,s2);
    }
    scanf("%s",a);
    getchar();
    while(gets(a)!=NULL)
    {
        if(a[0]=='E'&&a[1]=='N'&&a[2]=='D')
            break;
        int cnt=0;
        for(int i=0; i<strlen(a); i++)
        {

            if(a[i]>='a'&&a[i]<='z')
            {
                s2[cnt++]=a[i];
                continue;
            }
            else if(cnt>0)
            {
                s2[cnt]='\0';
                p(s2);
                cnt=0;
            }
                printf("%c",a[i]);
        }
        printf("\n");
    }

    return 0;
}
