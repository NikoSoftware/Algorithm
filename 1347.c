#include<stdio.h>
int main()
{
    float i,j,n;
    scanf("%f",&n);
    for(i=1;i<=3;i++)
    {
        printf("  %6.2f",n);
        for(j=1;j<i;j++)
        printf("   %6.2f",n);
        printf("\n");
    }
    return 0;
}
