#include<stdio.h>
int main()
{
    int i,m,sum;
    for(i=100;i<1000;i++)
    {
        m=i;
        sum=0;
        while(m)
        {
            sum+=(m%10)*(m%10)*(m%10);
            m=m/10;
        }
        if(i==sum)
        printf("%d\n",i);
    }
    return 0;
}
