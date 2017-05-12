#include<stdio.h>
int main()
{
    char a[100]={'A','H','I','M','O','T','U','V','W','X','Y'},b[5];
    while(scanf("%s",b)!=EOF)
    {
        int flag=0;
        for(int i=0;i<11;i++)
        {
            if(b[0]==a[i])
            {
                flag=1;
                printf("yes\n");
                break;
            }
        }
        if(flag==0)
            printf("no\n");
    }
}
