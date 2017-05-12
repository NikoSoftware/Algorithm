#include<stdio.h>
int main()
{
    int n,m,i,j,same,min,temp;
    scanf("%d%d",&n,&m);
    if(n>m)
   {
       temp=m;
    m=n;
    n=temp;
   }
    for(i=1;i<=n;i++)
    {
        if(n%i==0&&m%i==0)
        same=i;
    }
    printf("%d\n%d",same,(m*n)/same);
}
