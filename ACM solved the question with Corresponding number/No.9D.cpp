#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int data[10000],n,vis[10000];

struct Node
{
    int x,y,id;
} c[100000];
int cmp(struct Node a,struct Node b)
{
    if(a.y!=b.y)
        return a.y>b.y;
    return a.x<b.x;
}
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=data[x];
        x-=lowbit(x);
    }
}
void updata(int i,int x)
{
    while(i < 10000)
    {
        data[x]+=x;
        i += lowbit(i);
    }
}



int main()
{
    while(scanf("%d",&n),n)
    {
        memset(data,0,sizeof(data));
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&c[i].x,&c[i].y);
            c[i].id=i;
        }
        sort(c+1,c+n+1,cmp);

        vis[c[0].id] = sum(c[0].x);
        updata(c[1].x,1);



        for(int i=2; i<=n; i++)
        {
            if(c[i].x==c[i-1].x&&c[i].y==c[i-1].y)
                vis[c[i].id]=vis[c[i-1].id];
            else
                vis[c[i].id]=sum(c[i].x);
            updata(c[i].x,1);

        }
        printf("%d",vis[1]);
        for(int i=2; i<=n; i++)
            printf("%d ",vis[i]);
        printf("\n");
    }

    return 0;
}
