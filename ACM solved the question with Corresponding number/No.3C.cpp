#include<stdio.h>
#include<string.h>
char a[10000];

int main()
{
    int n,m=0;
    while(scanf("%s",a)!=EOF)
    {
        int flag=0;
        n=strlen(a);
        if(strcmp(a,"<br>")==0)
        {
            printf("\n");
            m=0;
            continue;
        }
        else if(strcmp(a,"<hr>")==0)
        {
            if(m!=0)
            printf("\n");
            for(int i=0;i<80;i++)
            printf("-");
            printf("\n");
            m=0;
            continue;
        }
        else
        {
           for(int i=0;i<n;i++)
           {
               m++;
               printf("%c",a[i]);
               if(m==80)
               {
                   printf("\n");
                   flag=1;
                   m=0;
               }
           }
           if(flag==0)
           {
               printf(" ");
               //m++;
               if(m==80)
               {
                   printf("\n");
                   m=0;
               }
           }
        }
    }

    return 0;
}
