#include<stdio.h>
#include<string.h>
int father[10000],relation[10000],flag=0;

int find(int d)
{
    if(d!=father[d])
    {
        int t=father[d];
        father[d]=find(father[d]);
        relation[d]=(relation[d]+relation[t]+1)%2;
    }
    return father[d];
}
void unit(int a,int b)
{
    int x,y;
    x=find(a);
    y=find(b);
    father[x]=y;
    relation[x]=(relation[b]-relation[a])%2;
}


int main()
{
    int k,n,m,s1,s2;
    scanf("%d",&k);
    int t=k;
    while(k--)
    {
        flag=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            father[i]=i;
            relation[i]=1;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&s1,&s2);
            if(find(s1)==find(s2))
            {
                if(relation[s1]==relation[s2])
                flag=1;
            }
            else
            {
                unit(s1,s2);
            }
        }
        printf("Scenario #%d:\n",t-k);
        if(flag)
        printf("Suspicious bugs found!\n");
        else
        printf("No suspicious bugs found!\n");
    }





    return 0;
}
