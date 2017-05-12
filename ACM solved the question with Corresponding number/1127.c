#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
       if(n/10>10)
       printf("Score is error!");
       else if(n/10>=9)
       printf("A\n");
       else if(n/10==8)
       printf("B\n");
       else if(n/10==7)
       printf("C\n");
       else if(n/10==6)
       printf("D\n");
       else
       printf("E\n");
    }
    return 0;
}
