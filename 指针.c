#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{
    int i,*n,*a;
n=(int *)malloc(sizeof(int));
a=(int *)malloc(sizeof(int)*100);
while(scanf("%d",n)!=EOF)
{
    for(i=0;i<*n;i++)
    scanf("%d",a+i);
    for(i=0;i<*n;i++)
    printf("%d ",*(a+i));
    printf("\n");
}
return 0;
}
