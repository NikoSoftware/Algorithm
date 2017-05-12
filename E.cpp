#include<stdio.h>
#include<string.h>
int set[200000],num[200000],dis[200000],n,m;

int find(int d)
{
    if(d!=set[d])
    {
        int temp=set[d];
        set[d]=find(set[d]);
        dis[d]+=dis[temp];
    }
        return set[d];

}
void mix(int x,int y)
{
     x=find(x);
     y=find(y);
    set[y]=x;
    dis[y]=num[x];
    num[x]+=num[y];
}

int main()
{
    int k;
    char key[10];
    scanf("%d",&k);
    for(int i=0; i<200000; i++)
     num[i]=1,dis[i]=0, set[i]=i;
    for(int i=0; i<k; i++)
    {
        scanf("%s",key);
        if(key[0]=='M')
        {
            scanf("%d%d",&n,&m);
            mix(n,m);
        }
        else
        {
            int t;
            scanf("%d",&n);
            t=find(n);
            printf("%d\n",num[t]-dis[n]-1);
        }
    }
    return 0;
}
