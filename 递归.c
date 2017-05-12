#include<stdio.h>
int g(int n);
int f(int n)
{
    n=g(n);
    return n;
}
int g(int n)
{
    n=n-1;
    return n;
}
int main()
{
    int n=3;
    n=f(n);
    printf("%d",n);
}
