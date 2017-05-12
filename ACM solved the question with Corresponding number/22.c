#include<stdio.h>
int main()
{
	int a,b,c,x;
		scanf("%d%d%d",&a,&b,&c);
		if(a>b)
		x=a;
		else
		x=b;

		if(x>c)
		printf("%d",x);
		else
		printf("%d",c);
		return 0;
}
