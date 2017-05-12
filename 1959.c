#include<stdio.h>
#include<math.h>
int main()
{
    int a[100],min,i,flag;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    min=a[0];
    flag=0;
    for(i=1;i<10;i++)
    {
        if(min>abs(a[i]))
        {
            min=a[i];
            flag=i;
        }
    }
    a[flag]=a[9];
    a[9]=min;
    for(i=0;i<9;i++)
    printf("%d ",a[i]);
    printf("%d",a[i]);
    return 0;
}
