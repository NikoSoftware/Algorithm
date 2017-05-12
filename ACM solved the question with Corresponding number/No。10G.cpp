#include<stdio.h>
#include<string.h>

long long sum[10000000],add[10000000];

void pushup(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
}


void build(int l,int r,int o)
{
    if(l==r)
    {
        scanf("%lld",&sum[o]);
        return;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1);
    build(m+1,r,o<<1|1);
    pushup(o);
}

void PushDown(int o,int m)
{
    if(add[o])
    {
        add[o<<1]+=add[o];
        add[o<<1|1]+=add[o];
        sum[o<<1]+=add[o]*(m - (m>>1));
        sum[o<<1|1]+=add[o]*(m>>1);
        add[o]=0;
    }
}


void updata(int L,int R,int c,int l,int r,int o)
{
    if(L<=l&&r<=R)
    {
        add[o]+=c;
        sum[o]+=(long long)c*(r-l+1);
        return;
    }
    PushDown(o,r-l+1);
    int m=(r+l)>>1;
    if(L<=m)
        updata(L,R,c,l,m,o<<1);
    if(R>m)
        updata(L,R,c,m+1,r,o<<1|1);
    pushup(o);
}

long long query(int a,int b,int l,int r,int o)
{
    if(a<=l&&r<=b)
    {
        return sum[o];
    }
     PushDown(o,r-l+1);
    int m=(l+r)>>1;
    long long res=0;
    if(a<=m)
    {
        res+=query(a,b,l,m,o<<1);
    }
    if(m<b)
        res+=query(a,b,m+1,r,o<<1|1);
    return res;

}


int main()
{
    int n,m,a,b,k;
    char s[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(int i=0; i<m; i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(a,b,1,n,1));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&k);
                updata(a,b,k,1,n,1);
            }
            /*for(int j=1;j<25;j++)
            {
                printf("%d ",sum[j]);
            }
            puts("");*/
        }
    }
    return 0;
}
