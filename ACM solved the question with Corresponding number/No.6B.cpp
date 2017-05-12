#include<stdio.h>
#include<string.h>
int map[1000][1000],data1[1000],data2[1000],n,m,vis[1000],count,data[1000];


void two(int a)
{
    if(a>data[count])
    {
        data[++count]=a;
        return ;
    }
    if(a<data[0])
    {
        data[0]=a;
        return ;
    }
    if(a<data[count])
    {
        int l=0,k=count;
        while(l<=k)
        {
            int mid = (l+k)/2;
            if(a>=data[mid]&&a<=data[mid+1])
            {
                data[mid+1]=a;
                return ;
            }
            else if(a>data[mid])
            l=mid+1;
            else
            k=mid-1;
        }
    }

}

void cal()
{
    data[0]=vis[0];
    for(int i=1;i<n;i++)
    {
        two(vis[i]);
    }

}

int main()
{
    int k,cnt;
    while(scanf("%d",&k)!=EOF)
    {
        count=0;
        memset(map,0,sizeof(map));
        for(int i=0;i<k;i++)
        {
            cnt=0;
            scanf("%d",&n);
            for(int j=1;j<=n;j++)
            scanf("%d",&data1[j]);
            scanf("%d",&m);
            for(int j=1;j<=m;j++)
            scanf("%d",&data2[j]);
            for(int j=1;j<=n;j++)
            {
                for(int z=1;z<=m;z++)
                {
                    if(data1[j]==data2[z])
                    {
                        map[j][z]=map[j-1][z-1];
                        vis[cnt++]=data1[j];
                    }
                    else
                    map[j][z]=(map[j-1][z]>=map[j][z-1]?map[j-1][z]:map[j][z-1]);
                }
            }
        }
        cal();
        printf("%d\n",count+1);

    }
}
