#include<stdio.h>
int main()
{
	int n,i=1,sum=1;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	sum=2*(sum+1);
	printf("%d\n",sum);
}
