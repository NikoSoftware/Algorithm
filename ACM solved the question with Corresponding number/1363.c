#include<stdio.h>
int main()
{
    int n,sum=0,i,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        sum+=a[i];
    }
    printf("%d",sum);

}
