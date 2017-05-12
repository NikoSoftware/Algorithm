#include<stdio.h>
#include<string.h>
char data[500000];
int next[500000],n,sum[400000];

void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<=n)
    {
        if(j==-1||data[i]==data[j])
        {
            next[++i]=++j;
        }
        else
        j=next[j];
    }
}

int main()
{
    while(scanf("%s",data)!=EOF)
    {
      n=strlen(data);
      getnext();
      int cnt=0;
      sum[cnt++]=n;
      while(next[n]!=0)
      {
          sum[cnt++]=next[n];
          n=next[n];
      }
      for(int i=cnt-1;i>0;i--)
      printf("%d ",sum[i]);
      printf("%d\n",sum[0]);
    }
    return 0;
}
