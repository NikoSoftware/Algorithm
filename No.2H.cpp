#include<stdio.h>
#include<string.h>
int k[100000],flag[100000];


int cha(int x)
{
  if(k[x]==x)
  return x;
  return k[x]=cha(k[x]);
}

void bing(int x,int y)
{
    x=cha(x);
    y=cha(y);
    if(x!=y)
    k[x]=y;

}




int main()
{
    int z=0,a,b,x,y;
    while(scanf("%d%d",&a,&b)&&a!=0&&b!=0)
    {
        z++;
        int sum=0;
        for(int i=1;i<=a;i++)
        {
            k[i]=i;
            flag[i]=0;
        }
        for(int i=1;i<=b;i++)
        {
            scanf("%d%d",&x,&y);
            bing(x,y);
        }
        for(int i=1;i<=a;i++)
        {
            //printf("%d ",k[i]);
            int  is=cha(i);
            if(flag[is]==0)
            {
                flag[is]=1;
                sum++;
            }

        }
        printf("Case %d: %d\n",z,sum);
    }

    return 0;
}
