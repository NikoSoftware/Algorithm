#include<stdio.h>
int dg(int x)
{
    int z;
    if(x==1)
     z=10;
     if(x>1)
     z=dg(x-1)+2;
    return z;
}
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        printf("%d\n",dg(x));
    }
}
