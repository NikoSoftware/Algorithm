#include<stdio.h>
//#include<string.h>
#include<memory.h>
int Strlen(char *strsp)
{
    int length=0;
        while(*strsp!='\0')
    {
        strsp++;
        length++;
    }
    return length;
}
int main()
{
    int i;
    char strs[3][41],*strsp[3];
    for(i=0;i<3;i++)
    {
        scanf("%s",strs[i]);
        strsp[i]=strs[i];
    }
    for(i=0;i<3;i++)
    {
        printf("第%d个字符串的长度为：%d\n",i+1,Strlen(strsp[i]));
    }
}

