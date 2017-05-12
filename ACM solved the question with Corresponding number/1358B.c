#include<stdio.h>
#include<string.h>
struct student
{
    char num[10];
    char name[20];
    int a,b,c;
}str[10];
int main()
{
    int n,i,sum1=0,sum2=0,sum3=0,ave1,ave2,ave3,sum[10],Max,f;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d %d %d",str[i].num,str[i].name,&str[i].a,&str[i].b,&str[i].c);
        sum[i]=str[i].a+str[i].b+str[i].c;
    }
     for(i=0;i<n;i++)
    {
        sum1+=str[i].a;
        sum2+=str[i].b;
        sum3+=str[i].c;
    }
    ave1=sum1/n;
    ave2=sum2/n;
    ave3=sum3/n;
    printf("%d %d %d\n",ave1,ave2,ave3);
      Max=sum[0];
      f=0;
    for(i=0;i<n;i++)
    {
        if(Max<sum[i])
      {
          Max=sum[i];
        f=i;
      }
    }
    printf("%s %s %d %d %d\n",str[f].num,str[f].name,str[f].a,str[f].b,str[f].c);

}
