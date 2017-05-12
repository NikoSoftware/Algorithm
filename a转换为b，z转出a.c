#include<stdio.h>

int main()
{
char str[80],c;
int i=0;
gets(str);
while(str[i]!='\0')
{

if(str[i]=='z'||str[i]=='Z')
str[i]=str[i]-25;
else if(str[i]>='a'&&str[i]<'z'||str[i]>='A'&&str[i]<'Z')
str[i]=str[i]+1;
  i++;
}
puts(str);
}
