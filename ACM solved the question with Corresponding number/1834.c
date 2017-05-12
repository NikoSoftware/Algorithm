#include<stdio.h>
int main()
{
    int i,j,n,count;
    while(1)
    {
        count=0;
        scanf("%d",&n);
        if(n==0)
        break;
        if(n==2)
        {
            printf("%d\n",2);
            continue;
        }
        for(i=1;i<=n;i++)
        {
            if((n-i)%2==0)
            count++;
        }
        printf("%d\n",count);
    }
}
