#include<stdio.h>
int main()
{
    int a[100],b[100];
    int i,j,m,n;
    scanf("%d%d",&n,&m);
    for(i=0;i<m+n;i++)
    {
    scanf("%d%d",&a[i],&b[i]);
    }
for(i=0;i<m+n-1;i++)
{
    for(j=0;j<m+n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
            t=b[j];
            b[j]=b[j+1];
            b[j+1]=t;
        }
    }
}
for(i=0;i<m+n;i++)
{
    printf("%d %d\n",a[i],b[i]);

}
return 0;
}







