#include<stdio.h>
int main()
{
	int a,i,count=0,sum=0;
	float ave;
	for(i=0;i<20;i++)
	{
		scanf("%d",&a);
	if(a<0)
		count=count+1;
	else
		sum+=a;
	}
	ave=(float)sum/(float)(20-count);
	printf("%d\n%.2f\n",count,ave);
	return 0;
}
