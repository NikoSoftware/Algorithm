#include<stdio.h>
int main()
{
    int i,n,a,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
    }
    if(sum<=1500)
    printf("YES\n");
    else
    printf("NO\n");

}
