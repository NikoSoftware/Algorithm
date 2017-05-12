#include<stdio.h>
#inclde<sting.h>
int main()
{
    int z,i,n,sum=0,sum1=0,sum2=0,sum3=0,sum4=0;
    char str[60];
    while(scanf("%d",&n)!=EOF)
{
      sum=0;
    for(i=0;i<n;i++)
     {
      scanf("%s",str);
        z=strlen(str);
        if(z>16||z<8)
       {
        printf("NO\n");
        continue ;
       }
        for(i=0;i<z;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                sum1=1;
            if(str[i]>='A'&&str[i]<='Z')
            sum2=1;
            if(str[i]>='0'&&str[i]<='9')
            sum3=1;
            if(str[i]=='~'||str[i]=='%'||str[i]=='@'||str[i]=='#'||str[i]=='!'||str[i]=='.'||str[i]=='^'||str[i]=='$')
            sum4=1;
        }
     }
        sum=sum1+sum2+sum3+sum4;
        if(sum<3)
        printf("NO\n");
        else
        printf("YES\n");
    }
}
