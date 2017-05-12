#include<stdio.h>
#include<string.h>
char Strcmp(char *s1,char *s2)
{
  while(*s1==*s2&&*s1)
  {
      s1++;
      s2++;
  }  return (*s1-*s2);
}
int main()
{
    int n;
    char s1[100],s2[100];
    while(gets(s1)!=NULL)
   {
       n=0;
       gets(s2);
    n=Strcmp(s1,s2);
    printf("%d\n",n);
   }
}
