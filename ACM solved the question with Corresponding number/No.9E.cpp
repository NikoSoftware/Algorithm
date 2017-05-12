#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int data[1000000],n,m,z;
long long ans;

struct Node
{
    int x,y;
} t[1000000];

int cmp(Node a,Node b)
{
    if(a.x==b.x)
        return a.y<b.y;
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
    return s;
}

void add(int i,int x)
{

    while(i<=1005)
    {
        data[i]+=x;
        i+=lowbit(i);
    }
}





int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        ans=0;
        memset(data,0,sizeof(data));
        scanf("%d%d%d",&n,&m,&z);
        m=max(n,m);
        for(int j=1; j<=z; j++)
        {
            scanf("%d%d",&t[j].x,&t[j].y);
        }
        sort(t+1,t+z+1,cmp);
        for(int j=1; j<=z; j++)
        {
            add(t[j].y,1);
            ans+=j-sum(t[j].y);

        }
        //for(int j=0;j<=m;j++)
        //printf("%d ",data[j]);
        printf("Test case %d: %lld\n",i+1,ans);
    }
    return 0;
}
