#include<stdio.h>
int main()
{
    int a[2][3];
    int n=2,m=3;
    int i,j;
    for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
    }

}
    int sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum+=a[i][j];
        }
    }
    printf("%d",sum);
    return 0;
}
