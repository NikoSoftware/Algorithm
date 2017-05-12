#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=200000;
//define max(int x,int y) x>y?x:Y

int max(int x,int y)
{

    return x>y?x:y;
}
int sum[maxn*4];
/*struct Node
{
    int x,max;

}sum[maxn*4];*/
void pushup(int o)
{
    sum[o]=max(sum[o<<1],sum[o<<1|1]);
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

/*int maxk(int L,int R,int l,int r,int o)
{
    if(l==r)
    {
        return sum[o];
    }
    int m=(l+r)>>1;
    int maxs=0,max1=0,max2=0;
    if(L<=m)
    {
        max1=maxk(L,R,l,m,o<<1);
    }
    if(m<=R)
    max2=maxk(L,R,m+1,r,o<<1|1);
    maxs=max(max1,max2);
    return maxs;
}*/
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




int main()
{
    int n,m,a,b;
    char s[10];
    scanf("%d%d",&n,&m);
    build(1,n,1);
    for(int i=0;i<m;i++)
    {
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='Q')
        {
            printf("%d\n",maxk(a,b,1,n,1));
        }
        else
        {
            b=b-query(a,a,1,n,1);
            updata(a,b,1,n,1);
        }
    }


    return 0;
}
