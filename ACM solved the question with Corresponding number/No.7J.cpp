#include<stdio.h>
#include<string.h>
char data[200][200],map[200];
int len[200],next[200],lenp,n;

void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<lenp)
    {
        if(j==-1||map[i]==map[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}
int KMP()
{
    int m=0,i=0,j=0;
    int ma=1000;
    getnext();
    for(int k=1; k<n; k++)
    {
        m=0,i=0,j=0;
        while(j<lenp&&i<len[k])
        {
            if(j==-1||data[k][i]==map[j])
            {
                i++;
                j++;
            }
            else
                j=next[j];
            if(j>m)
                m=j;
        }
        if(m<ma)
            ma=m;
    }

    //  printf("ma:%d\n",ma);
    return ma;
}
int main()
{
    int k,ma1,ma2,ma;
    while(scanf("%d",&k)!=EOF)
    {
        while(k--)
        {
            ma=0;
            scanf("%d",&n);
            for(int i=0; i<n; i++)
            {
                scanf("%s",data[i]);
                len[i]=strlen(data[i]);
            }
            for(int i=0; i<len[0]; i++)
            {
                strcpy(map,data[0]+i);
                lenp=strlen(map);
                //printf("%s\n",map);
                ma1=KMP();
                int cnt=0;
                for(int j=len[0]-i-1; j>=0; j--)
                {
                    map[cnt++]=data[0][j];
                }
                //printf("%s\n",map);
                ma2=KMP();
                ma=ma>(ma1>ma2?ma1:ma2)? ma:(ma1>ma2?ma1:ma2);
            }
            printf("%d\n",ma);
        }
    }
    return 0;
}
