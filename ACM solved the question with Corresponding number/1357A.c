#include<stdio.h>
#include<string.h>
struct student
{
    char num[10];
    char str[20];
    int a,b,c;
}student1[10];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d%d%d",student1[i].num,student1[i].str,&student1[i].a,&student1[i].b,&student1[i].c);
    }
    for(i=0;i<n;i++)
    printf("%s,%s,%d,%d,%d\n",student1[i].num,student1[i].str,student1[i].a,student1[i].b,student1[i].c);
}
