#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool map[100][200];
int a,b,c,y[5]={0,1,0,-1},x[5]={1,0,-1,0};
void Chang(int cur)
{

}

int main()
{
    while(scanf("%d",&a)!=EOF);
    {
        scanf("%d%c",&b,&c);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            scanf("%d",&map[i][j]);
        }
        Chang(c);
    }

    return 0;
}
