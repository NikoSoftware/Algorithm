#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,a[1000],max,index;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        a[m]++;
    }
    max=0,index=0;
    for(i=0;i<1000;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            index=i;
        }
    }
    printf("%d\n%d",index,max);
    return 0;
}
