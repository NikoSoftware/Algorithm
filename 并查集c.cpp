#include<stdio.h>
#include<string.h>

int set[100000],rank[100000];

int find(int d)

{
    if(d!=set[d])
    {
        set[d]=find(set[d]);
    }
    return set[d];
}
void unit(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    if(rank[x]>=rank[y])
    {
        set[y]=x;
        rank[x]=rank[x]+rank[y];
    }
    else
    {
        set[x]=y;
        rank[y]=rank[x]+rank[y];

    }
}


int main()
{
    int k,k1,key1,key2,n;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n==0&&k==0)
            break;
        for(int i=0; i<=n; i++)
        {
            rank[i]=1;
            set[i]=i;
        }
        for(int j=0; j<k; j++)
        {
            scanf("%d",&k1);
            scanf("%d",&key1);
            for(int i=1; i<k1; i++)
            {
                scanf("%d",&key2);
                unit(key1,key2);
            }
        }
        printf("%d\n",rank[set[0]]);
    }

    return 0;
}
