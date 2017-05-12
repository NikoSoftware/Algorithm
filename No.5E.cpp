#include<stdio.h>
#include<string.h>

int dp[100][100];


int main()
{
    int len1,len2;
    char str2[100],str1[100];
    while(scanf("%s%s",str1+1,str2+1)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        len1=strlen(str1+1);
        len2=strlen(str2+1);
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(str1[i]==str2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=(dp[i-1][j]>=dp[i][j-1] ? dp[i-1][j]:dp[i][j-1]);
                }
            }

        }
        printf("%d\n",dp[len1][len2]);
    }

    return 0;
}
