#include<stdio.h>
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        i=n;
        while(i!=1)
        {
            if(i%2==0)
            {
                i=i/2;
            printf("%d/2=%d\n",i*2,i);
            }
            else
            {
                i=i*3+1;
            printf("%d*3+1=%d\n",(i-1)/3,i);
            }
        }
    }
    return 0;
}
