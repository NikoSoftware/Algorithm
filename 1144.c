#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int n,m,i,z;
    while(scanf("%d",&z)!=EOF)
    {
        m=0;n=0;
        if(z==0)
        break;
        gets(a);
        for(i=0;i<z-1;i++)
        {
            if(a[i]=='Y')
                n++;
            if(a[i]=='R')
            m++;
        }
            if(a[z-1]=='L')
            {
                if(n>=7)
                printf("Yellow\n");
                else
                printf("Red\n");
            }
            if(a[z-1]=='B')
            {
                if(m>=7)
                printf("Red\n");
                else
                printf("Yellow\n");
            }
        }
    }

