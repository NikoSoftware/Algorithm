#include<stdio.h>
int main()
{
    int i,n,a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Case #%d: %d\n",i+1,a[i]);
    }

    return 0;
}
