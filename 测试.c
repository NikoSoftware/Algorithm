#include<stdio.h>

int Max();

int main()
{
    int num1=3,num2=5,result;
    result=Max(num1,num2);
    printf("Max=%d\n",result);
    getchar();
    getchar();

  return 0;
}

int Max(int n1,int n2)
{
    int r;
    if(n1>n2)
    r=n1;
    else
    r=n2;
    return r;
}

