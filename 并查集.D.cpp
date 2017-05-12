#include<stdio.h>
#include<string.h>

int set[400000],n,m,d1,d2;

int find(int d)
{
    if(set[d]<0)
    return d;
    return set[d]=find(set[d]);
}

int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        memset(set,-1,sizeof(set));
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++)
        {
            char a[10];
            scanf("%s%d%d",a,&d1,&d2);
            if(a[0]=='A')
            {
                if(find(d1)!=find(d2)&&find(d1)!=find(d2+n))
                puts("Not sure yet.");
                else if(find(d1)==find(d2))
                puts("In the same gang.");
                else
                puts("In different gangs.");
            }
            else
            {
                if(find(d1)!=find(d2+n))
                {
                    set[find(d1)]=find(d2+n);
                    set[find(d2)]=find(d1+n);
                }
            }

        }

    }
    return 0;
}
