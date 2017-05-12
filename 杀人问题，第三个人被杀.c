#include<stdio.h>
int main(void)
{
int count=0,k=0,i=0,m,a[100],x;
printf("请输入人数x");
scanf("%d",&x);
for(i=0;i<x;i++)
a[i]=1;
printf("请输入间隔m");
scanf("%d",&m);
for(;count<=x-1;i++)
{
if(a[i%x]!=0)
{
k=k+1;
if(k==m)
{
printf("%d ",(i%x)+1);
a[i%x]=0;
count++;
k=0;
}
}
}
return 0;
}
