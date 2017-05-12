#include<stdio.h>
#include<string.h>
char  a[20000000],b[200000];
int next[20000],an,bn,count;

void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<bn)
    {
        if(j==-1||b[i]==b[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}

void get()
{
    int j = 0;
    count=0;
    for(int i = 0; i < an; i++)
    {
        while(j > 0 && a[i] != b[j])
            j = next[j];
        if(a[i] == b[j])
        {
            if(j==bn-1)
            {
                count++;
            }
            j++;

        }
        else
            j = 0;
    }
}

int main()
{
    int k=0;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0; i<k; i++)
        {
            scanf("%s",b);
            scanf("%s",a);
            an=strlen(a);
            bn=strlen(b);
            getnext();
            get();
            printf("%d\n",count);

        }
    }


    return 0;
}
