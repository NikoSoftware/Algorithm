#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j;
    //char a[100]={'|','.','.','.','.','.','.','.','.','.','.','.','.','|'},b[100]={'|','-','-','-','-','-','-','-','-','-','-','-','-','|'};
    //char c[100]={}
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&m);
        printf("Case #%d:\n",j+1);
        printf("*------------*\n");
        for(i=0;i<100-m;i=i+10)
        {
            printf("|............|\n");
        }
        for(i=0;i<m;i=i+10)
        {
            printf("|------------|\n");
        }
        printf("*------------*\n");
    }
    return 0;
}
