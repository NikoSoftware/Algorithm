#include<math.h>
int main()
{
	float a,b,c,z,x1,x2;
	scanf("%f%f%f",&a,&b,&c);
	z=b*b-4*a*c;
	if(a==0&&b==0)
	return 0;
	if(a==0&&b!=0)
	{
		x1=-c/b;
	printf("%.2f\n",x1);
	}
	if(a!=0&&z<0)
		return 0;
	if(a!=0&&z==0)
	{
		x1=x2=-b/2*a;
	printf("%.2f %.2f\n",x1,x2);
	}
	if(a!=0&&z>0)
		{
			x1=(-b+sqrt(z))/(2*a);
	x2=(-b-sqrt(z))/(2*a);
	printf("%.2f %.2f\n",x1,x2);
	}
	return 0;
}
