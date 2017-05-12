#include<stdio.h>
int main()
{
    int n,i,sum,a;
    while(scanf("%d",&n)!=EOF)
  {

   if(n==0)
    break;
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum=sum+a;
    }
    printf("%d",sum);
}
    return 0;
}
