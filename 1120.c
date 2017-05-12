#include<stdio.h>
int main()
{
 int n,a,b,c;
 scanf("%d",&n);
 while(n--)
 {
  scanf("%d %d",&a,&b);
  if(a>=100)
   a=a%100;
  if(b>=100)
   b=b%100;
  c=a+b;
  if(c>=100)
   c=c%100;
  printf("%d\n",c);
 }
}
