
#include<stdio.h>
#include<string.h>
#include<math.h>
char a0[]={"vy!"},a1[]={"lxbb"},a3[]={"se"};
int n0=0,n1=0,n3=0;
long long feichangNBdedaima(char *s)
{
    int length=strlen(s),i;
    long long result=0;
    for(i=0; i<length; i++)
    {
        if(s[i]==a0[n0])
        {
            result+=0;
            n0++;
        }
        else if(s[i]==a1[n1])
        {
            result+=pow(10,(length-i-1))*1;
            n1++;
        }
        else if(s[i]==a3[n3])
        {
            result+=pow(10,(length-i-1))*3;
            n3++;
        }
        else
        {
            switch(s[i])
            {
            case 'r':
                result+=pow(10,(length-i-1))*2;
                break;
            case 'n':
                result+=pow(10,(length-i-1))*6;
                break;
            default :
                result+=pow(10,(length-i-1))*998*222;
                break;
            }
        }
    }
    return result;
}
int main()
{
    char s[100];
    puts("É§ÄêÇëÊäÈëÃÜÂë£º");
    scanf("%s",s);
    printf("ÖÐ½±ºÅÂë£º%lld ¸Ï½ôÈ¥Âò²ÊÆ±£¡",feichangNBdedaima(s));
    return 0;
}
