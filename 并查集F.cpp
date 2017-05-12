#include<stdio.h>
#include<string.h>
int rank[10000];

struct node
{
    int x,y;
    int flag;
}queue[10000];

int find(int d)
{
    if(d!=rank[d])
    {
        rank[d]=find(rank[d]);
    }
    return rank[d];
}
void unit(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
    return;
    if(x>y)
    {
        rank[x]=y;
    }
    else
    rank[y]=x;
}
int main()
{
    int n,d,m;
    char a[10];
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
    {
        queue[i].flag=0;
        rank[i]=i;
        scanf("%d%d",&queue[i].x,&queue[i].y);

    }
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]=='O')
        {
            scanf("%d",&m);
            queue[m].flag=1;
            for(int i=1;i<=n;i++)
            {
                if(m!=i&&((queue[m].x-queue[i].x)*(queue[m].x-queue[i].x)+(queue[m].y-queue[i].y)*(queue[m].y-queue[i].y))<=d*d&&queue[i].flag==1)
                {

                    unit(m,i);
                }
            }
        }
        if(a[0]=='S')
        {
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            if(find(n1)==find(m1))
            {
                puts("SUCCESS");
            }
            else
            puts("FAIL");
        }

    }


    return 0;
}
