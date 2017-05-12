#include<stdio.h>
#include<string.h>
int main()
{
    int str[1000],n,m,i,j,tem;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&str[i]);
            for(i=0;i<n;i++)
            {
                for(j=i;j<n;j++)
                {
                    if(str[i]>str[j])
                    {
                        tem=str[i];
                        str[i]=str[j];
                        str[j]=tem;
                    }
                 }

           }
           for(i=0;i<n-1;i++)
           {
               printf("%d ",str[i]);
           }
           printf("%d\n",str[n-1]);
     }
}
