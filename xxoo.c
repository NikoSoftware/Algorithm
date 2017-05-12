#include<stdio.h>
int strlen(char *str);
void main()
{
    char strs[3][41];
    char *strsp[3];
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%s",strs[i]);
       strsp[i]=strs[i];
    }
for(i=0;i<3;i++)
{
    printf("%d~~~%d\n",i+1,strlen(strsp[i]));

}
}
int strlen(char *str)
{
    int length=0;
    while(*str!='\0')
    {
        str++;
        length++;
    }
    return length;



}
