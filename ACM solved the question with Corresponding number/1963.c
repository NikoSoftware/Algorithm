#include<stdio.h>
#include<string.h>
int main()
{
    int a[100][100],n,i,j,z=0,w=0,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    max=a[0][0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
       {
           if(max<a[i][j])
           {
               max=a[i][j];
               z=i;
               w=j;
           }
       }
    }
    printf("%d %d %d",max,z+1,w+1);
}
