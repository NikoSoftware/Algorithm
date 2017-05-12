#include<stdio.h>

int k[100000];

int cha(int x)
{
    if(k[x]==x)
    {
        return x;
    }
    return k[x]=cha(k[x]);
}
void bing(int x,int y)
{
     x=cha(x);
     y=cha(y);
    if(x!=y)
    k[y]=x;

}

int main()
{
    int n,m,a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            k[i]=i;
        }

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)
            {
                if(b>n||c>n||b==c)
                {
                    sum++;
                }
                else
                {
                    b=cha(b);
                    c=cha(c);
                    if(b==c)
                    continue;
                    else
                    sum++;
                }
            }

        }

        printf("%d\n",sum);
    }



    return 0;
}
