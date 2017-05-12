#include<stdio.h>
int main()
{
    int a[100],i,j,flag;
    for(i=0;i<20;i++)
    scanf("%d",&a[i]);
    for(i=0;i<20;i++)
    for(j=0;j<20;j++)
    {
        if(i==j)
        continue;
        if(a[i]%a[j]==0)
        {
            printf("%d\n",a[i]);
            break;
        }
    }
    return 0;
}
