#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m,j,z;
    char a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        memset(a,' ',sizeof(a));
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            for(z=0;z<m;z++)
            {
                if(j==z)
                a[j][j]='X';
                if(j==m-1-z)
                a[j][z]='X';
            }
        }
        for(z=0;z<m;z++)
        {
            int k=0;
            for(j=0;j<m;j++)
            {
                printf("%c",a[z][j]);
                if(a[z][j]=='X')
                {
                    k++;
                }
                if(k==2)
                break;
                if(j==z&&j==m/2)
                {
                    break;
                }
            }
        printf("\n");
        }
    }
    return 0;
}
