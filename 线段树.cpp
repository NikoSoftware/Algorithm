#include<stdio.h>
#include<string.h>
const int maxn=100000;

int sum[maxn*4];
void pushup(int o)
{
    sum[o]=sum[o<<1]+sum[o<<1|1];
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        scanf("%d",&sum[o]);
        return;
    }
    int m=(l+r)/2;
    build(l,m,o*2);
    build(m+1,r,o*2+1);
    pushup(o);

}

void updata(int x,int d,int l,int r,int o)
{
    if(l==r&&x==r)
    {
        sum[o]+=d;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)
    updata(x,d,l,m,o<<1);
    else
    updata(x,d,m+1,r,o<<1|1);
    pushup(o);
}
/*void pushdown(int o)
{
    sum[o<<1]+=mar[o];
    sum[o<<1|1]+=mar[o];
    mar[o]=0;

}
*/

int query(int L,int R,int l,int r,int o)
{
    if(L<=l&&r<=R)
    {
        return sum[o];
    }
    //if(mar[o])
    //pushdown(o);
    int m=(l+r)>>1;
    int res=0;
    if(L<=m)
    {
        res+=query(L,R,l,m,o<<1);
    }
    if(m<R)
    res+=query(L,R,m+1,r,o<<1|1);
    return res;

}


int a[10000];

int main()
{
    int t,p=0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++p);

        int n;
        scanf("%d",&n);
        build(1,n,1);
        char op[10];
        while(~scanf("%s",op)&&op[0]!='E')
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(op[0]=='A')
            updata(a,b,1,n,1);
            else if(op[0]=='S')
                updata(a,-b,1,n,1);
            else
            printf("%d\n",query(a,b,1,n,1));
        }


    }



    return 0;
}
