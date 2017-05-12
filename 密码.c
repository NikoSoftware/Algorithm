#include<stdio.h>
#include<string.h>
int main()
{
    int z,i,j,n;
    char str[60];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        int sum=0,sum1=0,sum2=0,sum3=0,sum4=0;
        scanf("%s",str);
        //getchar();
        //gets(str);
        z=strlen(str);
        for(j=0; j<z; j++)
        {
            if(str[j]>='a'&&str[j]<='z')
                sum1=1;
            else if(str[j]>='A'&&str[j]<='Z')
                sum2=1;
            else if(str[j]>='0'&&str[j]<='9')
                sum3=1;
            else
                sum4=1;
        }
        sum=sum1+sum2+sum3+sum4;
        if(sum >= 3 && (z>=8 && z <= 16))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
