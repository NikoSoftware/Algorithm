#include<stdio.h>
int main()
{
    int i;
    for(i=11;i<1000;i++)
    {
        if(i%2==0&&i%3==0&&i%7==0)
        printf("%d\n",i);
    }
}
