#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m,sum,flag;
    char a[100];
    while(scanf("%s",a)!=EOF)
    {
        m=0;
        flag=0;
        n=strlen(a);
        for(i=0; i<n; i++)
        {
            //if((a[i]<'0'||a[i]>'9')&&a[i]!='.')
            if(!(a[i] >= '0' && a[i] <= '9' || a[i] == '.'))
            {
                flag=1;
                printf("N\n");
                break;
            }
        }
        //int f=1,z=0,j;
            sum=0;
        for(i=0; i<n; i++)
        {
            if(flag==1)
                break;
            if(a[i]!='.')
            {
                sum=sum*10+a[i]-'0';

            }

            else
            {

                ++m;
                if(sum<0||sum>255)
                {
                    printf("N\n");
                    break;
                }
                sum=0;
            }
        }
        if(m==3&&(sum>=0&&sum<=255))
            printf("Y\n");
    }
    return 0;
}
