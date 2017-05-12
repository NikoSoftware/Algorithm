#include<stdio.h>
#include<string.h>
int main()
{
    int a[10],i,j,n,z;
    for(i=0;i<9;i++)
    scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i=0;i<9;i++)
    {
        if(n<=a[i])
          {
              z=i;
              break;
          }
    }
    for(i=9;i>z;i--)
    {
        a[i]=a[i-1];
    }
    a[z]=n;
    for(i=0;i<10;i++)
    printf("%d\n",a[i]);
}
