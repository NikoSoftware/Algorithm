#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,j,m,z,b[100],k;
    char a[100];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        int flag=0;
        memset(b,0,sizeof(b));
        scanf("%s",a);
        scanf("%d",&k);
        m=strlen(a);
        for(j=0; j<m; j++)
        {
            if(a[j]<'A')
            {
                b[a[j]-'a']++;
                if(b[a[j]-'a']==k)
                {
                    printf("%c\n",a[j]);
                    flag=1;
                    break;
                }
            }
            else
            {
                b[a[j]-'A']++;
                if(b[a[j]-'A'+27]==k)
                {
                    printf("%c\n",a[j]);
                    flag=1;
                    break;
                }
            }

        }
        if(flag==0)
        {
            z=0;
            int max=b[0];
            for(k=1; k<50; k++)
            {
                if(max<=b[k])
                {
                    max=b[k];
                    z=k;
                }
            }
            printf("%c\n",'A'+z);
        }
    }

    return 0;
}
