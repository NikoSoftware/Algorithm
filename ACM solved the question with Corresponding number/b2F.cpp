#include<stdio.h>
#include<string.h>
int main()
{
    int i,sum,n,j,z,flag,k;
    char a[1000000];
    while(scanf("%s",a)!=EOF)
    {
        n=strlen(a);
         for(k=1;k<n;k++)
             {
                 int flag1=0;
                 if(a[n-1]==a[k])
                 {
                     for(z=k+1;z<=(k+n)/2;z++)
                     {
                         if(a[z]!=a[n-z-1-1])
                         flag1=1;
                     }
                     if(flag1==0)
                     break;
                 }
             }
        for(i=k+n-1; i<2*n; i++)
        {
             flag=0;
            for(j=n; j<=i; j++)
            {
                a[j]=a[i-j];
            }
            for(z=0; z<i/2; z++)
            {
                if(a[z]!=a[i-z])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("%d\n",j-n);
                break;
            }
        }
    }
}
