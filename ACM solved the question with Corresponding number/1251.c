#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],n,i,count=0;
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    scanf("%d",&n);
    for(i=0;i<10;i++)
    {
        if(a[i]<=(n+30))
        count++;
    }
    printf("%d\n",count);

}
