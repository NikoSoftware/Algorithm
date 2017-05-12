#include<stdio.h>
int Swap(int *a,int *b);
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d %d\n",a,b);
        Swap(&a,&b);
        printf("%d %d",a,b);
    }
}
int Swap(int *a,int *b)
{
    int p;
    p=*b;
    *b=*a;
    *a=p;
}
