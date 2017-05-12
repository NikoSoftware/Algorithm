#include<stdio.h>
int main()
{
    int n,a[10000],i,min,max;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        max=min=a[0];
        for(i=0;i<n;i++)
        {
            if(max<a[i])
            max=a[i];
            else if(min>a[i])
            min=a[i];
        }
        printf("%d %d\n",min,max);
    }

}
