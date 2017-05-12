#include<stdio.h>
int print();
int print()
{
    int i,j;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=9*i;j+=i)
        {
            printf("%4d",j);
        }
        printf("\n");
    }

    return 0;
}
int main()
{
    print();
    return 0;
}
