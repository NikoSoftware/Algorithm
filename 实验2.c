#include<stdio.h>
int main()
{
  int i,n;
  long long sum=0,t=1;
  scanf("%d",&n);
  if(n==0)
  sum=1;
  for(i=1;i<=n;i++)
 { t=t*i;
  sum=sum+t;}
  printf("%lld\n",sum);
  return 0;

}
