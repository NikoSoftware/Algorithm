#include<stdio.h>
int main()
{
  long long i,n,sum=0,product=1,j;
	scanf("%lld",&n);
	if(n<=0)
		return 0;
	for(i=1;i<n+1;i++)
	{
		for(j=i;j<i+1;j++)
			  product=product*j;
		sum=sum+product;
	}
	printf("%lld\n",sum);
	return 0;
}
