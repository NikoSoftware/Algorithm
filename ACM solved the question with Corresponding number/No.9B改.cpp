#include<stdio.h>
#include<string.h>

struct Node
{
    int l,r,max;
} t[1000000];

int max(int x,int y)
{
    return x>y?x:y;
}

void pushup(int l,int r,int o)
{
    t[o].max=max(t[o<<1].max,t[o<<1|1].max);
    t[o].l=l;
    t[o].r=r;
}

void build(int l,int r,int o)
{
    if(l==r)
    {
        scanf("%d",&t[o].max);
        t[o].l=t[o].r=l;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1);
    build(m+1,r,o<<1|1);
    pushup(l,r,o);

}
void updata(int a,int b,int l,int r,int o)
{
    if(l==r&&l==a)
    {
        t[o].max=b;
        return;
    }
    int m=(l+r)>>1;
    if(a<=m)
    {
        updata(a,b,l,m,o<<1);
    }
    else
        updata(a,b,m+1,r,o<<1|1);
    pushup(l,r,o);

}

int  maxs(int a,int b,int l,int r,int o)
{
    if(a==l&&r==b)
    {
        return t[o].max;
    }
    int m=(l+r)>>1;
    if(b<=m)
    {
        return maxs(a,b,l,m,o<<1);
    }
    else if(a>m)
    {
        return maxs(a,b,m+1,r,o<<1|1);
    }
    else
        return max(maxs(a,m,l,m,o<<1),maxs(m+1,b,m+1,r,o<<1|1));
}



int main()
{
    int n,m,a,b;
    char s[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(int i=0; i<m; i++)
        {
            scanf("%s%d%d",s,&a,&b);
            if(s[0]=='Q')
            {
                printf("%d\n",maxs(a,b,1,n,1));
            }
            else
            {
                updata(a,b,1,n,1);
                /*for(int i=1;i<15;i++)
                {
                    printf("%d ",t[i].max);
                }
                printf("\n");*/
            }
        }
    }
    return 0;
}
