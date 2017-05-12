#include<stdio.h>
#include<string.h>
int main()
{
   int n,i,j,z=0,p,k=1,a[1000];
   while(scanf("%d",&n)!=EOF)
   {
    memset(a,0,sizeof(a));
    a[0]=1;
    while(1)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(k%3==0)
                {
                    a[i]=1;
                    p=i;
                    z++;
                }
                k++;
            }
        }
        if(z==n)
        break;
    }
    printf("%d\n",p);
   }
    return 0;
}

