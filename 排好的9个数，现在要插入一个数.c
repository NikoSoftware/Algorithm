#include<stdio.h>
int main()
{
	int i,a[15],max,t,temp;

	for(i=0;i<=8;i++)
	scanf("%d",&a[i]);
	scanf("%d",&a[9]);
	max=a[9];

	for(i=0;i<=9;i++)
	{
		if(a[i]>max)
		{
			t=i;
			temp = a[i];
			a[i] = a[9];
			for(t=9;t>i;t--)
			{
				if(t == i+1)
				{
					a[t] = temp;
				}
				else
				{
					a[t]=a[t-1];
				}
			}
			break;
		}
	}

	for(i=0;i<=8;i++)
		printf("%d\n",a[i]);
    printf("%d",a[9]);
	return 0;
}
