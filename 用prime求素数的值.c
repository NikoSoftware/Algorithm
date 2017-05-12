#include<stdio.h>
#include<math.h>
int isprime(int i)
{
    int j;
    if(i==1)
    return 0;
    else
    for(j=i-1;j>1;j--)
    {
        if(i%j==0)
        return 0;
    }
      return i;

}
int main()
{
    int n,m,i;
   while(scanf("%d%d",&m,&n)!=EOF)
   {
    if(n<m)
    return 0;
    int sum=0;
    for(i=m;i<=n;i++)
    {
        sum+=isprime(i);
    }
    printf("%d\n",sum);
    }
    return 0;
}
