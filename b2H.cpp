#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    srand((int)time(0));
    printf("%d\n",rand()%50);
    return 0;
}
