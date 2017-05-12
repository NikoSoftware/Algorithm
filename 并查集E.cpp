#include<stdio.h>
#include<string.h>

int set[100000],n,cur,m;

int find(int d,int cur)
{
    if(set[d]<-1)
    return d;
    cur++;
    return set[d]=find(set[d]);
}
int main()
{
    int k;
    char key[10];
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        cur=0;
        scanf("%s",key);
        if(key[0]=='M')
        {
            scanf("%d%d",&n,&m);
            set[n]=m;
        }
        else
        {
           scanf("%d",&n);
           m=find(n,0);
           printf("%d\n",cur);
        }
    }
    return 0;
}
