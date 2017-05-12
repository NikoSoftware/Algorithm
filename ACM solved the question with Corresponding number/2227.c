#include<stdio.h>
char x[1000];
int s[1000],cou;
void xian1(int index)
{
    s[index]=cou++;
    if(x[s[index]-1]!='#')
    {
        xian1(index*2);
        xian1(index*2+1);
    }
}
void xian2(int index,int deep)
{
    int i;
    if(x[s[index]-1]=='#')
    return ;
    for(i=0;i<deep;i++)
    {
        printf("   ");
    }
    printf("%c\n",x[s[index]-1]);
    xian2(index*2,deep+1);
    xian2(index*2+1,deep+1);
}
int main()
{

  while(scanf("%s",x)!=EOF)
    {
        cou=1;
        if(x[0]=='#')
           break;
        xian1(1);
        xian2(1,0);
        printf("\n");
    }
    return 0;
}
