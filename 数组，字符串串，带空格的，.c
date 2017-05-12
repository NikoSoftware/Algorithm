#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    int len,i;
    while(scanf("%s",&str)!=EOF)
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z');
            {
                str[i]=str[i]-32;
            }
             printf("%c",str[i]);
        }
         printf("\n");//可以直接用  printf("%s",str);
    }
    return 0;
}
