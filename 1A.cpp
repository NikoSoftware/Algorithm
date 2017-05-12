#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,sum;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        sum=a-b;
        if(sum>=0)
        printf("%d\n",sum);
        else
        printf("%d\n",-sum);
    }
    return 0;
}
