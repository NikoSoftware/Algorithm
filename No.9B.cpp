#include<stdio.h>
#include<string.h>

int data[100005],a[100005],c[100005],s,n,m;

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

void add(int i,int x,int s)
{

    while(i<=s)
    {
        data[i]+=x;
        i+=lowbit(i);
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(data,0,sizeof(data));
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            add(i+1,1,n+1);
        }
        for(int i=0;i<m;i++)
        scanf("%d",&c[i]);
        for(int i=0; i<m-1; i++)
        {
            s=c[i];
            printf("%d ",sum(s)-a[s]);
            int k=sum(s)-a[s];
            for(int j=0;j<i;j++)
            if(c[j]>s)
            a[c[j]]--;


           /* for(int i=0;i<10;i++)
            {
                printf("%d ",a[i]);
                printf("%d:%d ",i,data[i]);
            }
            puts("");*/

            add(1,1,k);a[s]=sum(s);

        }
        s=c[m-1];
        printf("%d",sum(s)-a[s]);
        printf("\n");

    }
    return 0;
}
