#include<stdio.h>
int main()
{
    int i,j,n,sum,z,a;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&z);
        sum=0;
        for(j=0;j<z;j++)
       {
        scanf("%d",&a);
        sum+=a;
       }
        printf("%d\n\n",sum);
    }
    return 0;
}
