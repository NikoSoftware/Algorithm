#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,str[2][3],a[3][2];
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&str[i][j]);
            a[j][i]=str[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
         printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
