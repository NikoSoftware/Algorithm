#include<stdio.h>
int main()
{
    int i,j,n,z;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    for(z=i;z<n-1;z++)
    printf(" ");
    for(j=0;j<=i;j++)
    printf("*");
    for(j=1;j<=i;j++)
        printf("*");
    printf("\n");
    }
    return 0;
}
