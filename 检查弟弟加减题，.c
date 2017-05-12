#include<stdio.h>
#include<string.h>

int main()
{    char str[1001],opa,opb;
     int len,a,b,c,ans=0;
while(scanf("%s",str)!=EOF)
{
      len=strlen(str);
      if(str[len-1]=='?')
       continue;
       sscanf(str,"%d%c%d%c%d",&a,&opa,&b,&opb,&c);
       if(opa=='+')
       {
           if(a+b==c)
            ans++;
       }
       else
       {
           if(a-b==c)
           ans++;
       }


}
printf("%d\n",ans);
    return 0;

}
