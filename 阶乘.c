#include<stdio.h>
#include<string.h>
int main()
{
    int z,i,n,sum=0,sum1=0,sum2=0,sum3=0,sum4=0;
    char str[60];
    scanf("%d",&n);
{
      sum=0;
    for(i=0;i<n;i++)
     {
      scanf("%s",str);
        z=strlen(str);
        for(i=0;i<z;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                sum1=1;
            else if(str[i]>='A'&&str[i]<='Z')
            sum2=1;
            else if(str[i]>='0'&&str[i]<='9')
            sum3=1;
            else
            sum4=1;
        }
     }
        sum=sum1+sum2+sum3+sum4;
        if(sum >= 3 && (z>=8 && z <= 16))
            printf("Yes\n");
        else
        printf("No\n");
    }
}
