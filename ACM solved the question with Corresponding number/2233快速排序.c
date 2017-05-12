#include<stdio.h>
#include<string.h>
int a[2000000];
int sb(int left,int right,int k)
{
    //µİ¹é½áÊø
    if(left==right)
    {
        if(k==a[left])
        return left;
        else
        return -1;
    }
    int mid=(left+right)/2;
    if(k<=a[mid])
    {
      return sb(left,mid-1,k);
    }
    else
    {
      return sb(mid+1,right,k);
    }
}
int main()
{
    int m,n;
    int i,k;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    while(n--)
    {
        scanf("%d",&k);
        printf("%d\n",sb(0,m-1,k));
    }
    }
}
