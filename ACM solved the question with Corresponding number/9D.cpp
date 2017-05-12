#include<stdio.h>
#include<string.h>
int main()
{
    int data[100000],n,m,k,a,b;
    char c[10];
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&n,&m);
        memset(data,0,sizeof(data));
        for(int i=0;i<m;i++)
        {
            scanf("%s%d%d",&c,&a,&b);
            if(c[0]=='D')
            {
                if(data[a]==0)
                {
                    if(data[b]==1)
                    data[a]=2;
                    else if(data[b]==2)
                    data[a]=1;
                    else
                    {
                    data[a]=1;
                   data[b]=2;
                    }
                }
                else if(data[a]==1)
                {
                    data[b]=2;
                }
                else
                data[b]=1;

            }
            if(c[0]=='A')
            {
                if(data[a]==0||data[b]==0)
                {
                    printf("Not sure yet.\n");
                }
                else if(data[a]!=data[b])
                {
                    printf("In different gangs.\n");
                }
                else
                printf("In the same gang.\n");
            }
            for(int j=1;j<=n;j++)
            printf("%d ",data[j]);
            printf("\n");
        }
    }

    return 0;
}
