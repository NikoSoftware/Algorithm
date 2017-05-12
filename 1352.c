#include<stdio.h>
int main()
{
    int i,j,max,min,flag1=0,flag2=0,a[100];
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    max=a[0],min=a[0];
    for(i=0;i<10;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            flag2=i;
        }
        if(min>a[i])
        {
            min=a[i];
            flag1=i;
        }
    }
    a[flag2]=a[9];
    a[9]=max;
    a[flag1]=a[0];
    a[0]=min;
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    return 0;
}
