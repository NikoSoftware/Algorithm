#include<stdio.h>
int main()
{
    int n,m,i,j=0,f,sum;
    scanf("%d",&n);
        m=n/5;
    for(i=1;i<m;i++)
    {
        sum=n-5*i;
        while(sum>2)
        {
            sum-=2;
            j++;
        }
    }
    printf("%d\n",j);
}
