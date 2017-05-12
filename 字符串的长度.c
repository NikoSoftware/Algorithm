#include<stdio.h>
char s[100];
int len(int i)
{
    if(s[i]=='\0')
    {
        return i;
    }
    int chang=len(i+1);
    return chang;
}
int main()
{
    scanf("%s",s);
    printf("%d",len(0));
}
