#include<stdio.h>
#include<stdlib.h>
main()
{
	static int a[10]={1,7,8,17,23,24,59,62,101};
	int i,j,t;
    scanf("%d",&a[9]);
    for(i=9;i>0;i--)
    if(a[i]<a[i-1])
    {
		t=a[i-1];
		a[i-1]=a[i];
		a[i]=t;
	}
   for(i=0;i<10;i++)
   printf("%5d",a[i]);
   printf("\n");
   system("pause");
}








