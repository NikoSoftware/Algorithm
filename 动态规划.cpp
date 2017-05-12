#include<stdio.h>

int map[100][100];
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<=i;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=k-1;i>=0;i--)
        {
            for(int j=0;j<i;j++)
            {
               map[i][j]+map[i-1][j] > map[i-1][j]+map[i][j+1] ?map[i-1][j]+=map[i][j] : map[i-1][j]+=map[i][j+1];
            }
        }
        printf("%d\n",map[0][0]);


    }

    return 0;
}
