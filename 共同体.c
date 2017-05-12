#include<stdio.h>
union ad
{
    int i;
    char ch;
    float c;
}a.i=46;
int main()
{
    printf("%d %c,%f",a.i,a.ch,a.c);
}
