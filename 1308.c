#include<stdio.h>
#include<string.h>
void print(char n[] )
{
    printf("%s\n",n);
}
int main()
{
    char a[100],b[100],c[100];
    gets(a);
    gets(b);
    gets(c);
    print( a);
    print(b);
     print(c);

}
