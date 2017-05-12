#include<stdio.h>
#include<string.h>

char s1[6000],s2[6010];
int map[2][6005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        scanf("%s",s1+1);
        int m=1;
        for(int i=n; i>0; i--)
        {
            s2[m++]=s1[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i]==s2[j])
                    map[i%2][j]=map[(i-1)%2][j-1]+1;
                else
                    map[i%2][j]=(map[(i-1)%2][j]>=map[i%2][j-1]?map[(i-1)%2][j]:map[i%2][j-1]);
            }
        }
        printf("%d\n",n-map[n%2][n]);
    }
    return 0;

}
