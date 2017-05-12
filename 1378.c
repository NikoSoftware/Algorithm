#include<stdio.h>
#include<string.h>
int main()
{
    int i,a[3],b[3],c[3];
     for(i=0;i<3;i++)
     scanf("%d",&a[i]);
     for(i=0;i<3;i++)
     scanf("%d",&b[i]);
     for(i=0;i<3;i++)
     scanf("%d",&c[i]);

    printf("%d",a[0]+b[1]+c[2]);
}
