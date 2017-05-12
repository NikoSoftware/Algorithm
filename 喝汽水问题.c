#include<stdio.h>
int main()
{
    int n,i=1,a,b,c=0,z;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
            if(n==0)
        return 0;
        else
            a=n;
        while(a>2)
        {
            i++;
            z=a/3;
            c=a%3;
            a=c+z;
            sum+=z;
        }
       if(a==2)
          sum+=1;
        printf("%d\n",sum);
    }
    return 0;
}
