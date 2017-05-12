#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,z,i,j,f,a[100][100];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d%d",&m,&z);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        while(z!=0)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    if(a[i][j]==1)
                    {
                        if(a[i-1][j]==0)
                        a[i-1][j]=2;
                        if(a[i][j-1]==0)
                        a[i][j-1]=2;
                        if(a[i][j+1]==0)
                            a[i][j+1]=2;
                        if(a[i+1][j]==0)
                            a[i+1][j]=2;
                    }
                }
                for(f=0; f<n; f++)
                {
                    for(j=0; j<m; j++)
                    {
                        if(a[f][j]==2)
                        {
                            a[f][j]=1;
                        }
                    }
                }
            }
            z--;
        }

        printf("qwweqweq\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<m-1; j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d\n",a[i][m-1]);
        }
    }
    return 0;
}
