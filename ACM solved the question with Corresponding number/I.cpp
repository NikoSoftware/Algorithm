#include<stdio.h>
int main()
{
    int n,i,j,a,b,c;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",a+b+c);
    }
    return 0;
}
