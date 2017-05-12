#include<stdio.h>
#include<string.h>
int main()
{
    char a[10],b[20]={'A','H','I','M','O','T','U','V','W','X','Y'};
    while(scanf("%s",a)!=EOF)
    {
        int flag=0;
        for(int i=0;i<=11;i++)
        {
            if(a[0]==b[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("yes\n");
        else
        printf("no\n");
    }
    return 0;
}
