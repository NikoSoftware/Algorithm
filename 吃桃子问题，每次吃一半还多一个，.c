#include<stdio.h>
int main()
{
    int i,z,n;
    scanf("%d",&n);
    for(i=1,z=1;i<n;i++)
    z=(z+1)*2;
    printf("%d\n",z);
    return 0;
}
