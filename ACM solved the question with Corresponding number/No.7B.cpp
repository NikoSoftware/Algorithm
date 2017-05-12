#include<stdio.h>
#include<string.h>

char map[5000][210],vis[300],mid[300];
int n,k,len[5000],lenp,next[300],ma;

void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<lenp)
    {
        if(j==-1||mid[i]==mid[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}
void getnext1()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<strlen(vis))
    {
        if(j==-1||vis[i]==vis[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}


void KMP()
{
    int m,i,j;
    ma=100;
    getnext();
    for(int z=1; z<k; z++)
    {
        i=0;
        j=0;
        m=0;
        while(i<len[z]&&j<lenp)
        {
            if(j==-1 || map[z][i]==mid[j])
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
}


int main()
{
    while(scanf("%d",&k)!=EOF&&k!=0)
    {
        for(int i=0; i<k; i++)
        {
            scanf("%s",map[i]);
            len[i]=strlen(map[i]);
        }
        int ans=0;
        for(int i=0; i<len[0]; i++)
        {
            strcpy(mid,map[0]+i);
            lenp=len[0]-i;
            KMP();
            if(ans<ma)
            {
                ans=ma;
                strncpy(vis,map[0]+i,ans);
                vis[ans]='\0';
            }
            if(ans==ma)
            {
                char tmp[100];
                strncpy(tmp, mid, ans);
                tmp[ans] = '\0';
                if(strcmp(tmp, vis) < 0)
                    strcpy(vis, tmp);
            }

        }
        //printf("ans:%d\n",ans);
        if(ans==0)
            printf("IDENTITY LOST\n");
        else
        {
            /*getnext1();
            int len1=strlen(vis);
            if(len1%(len1-next[len1])==0)
            {
                for(int i=0; i<len1/(len1-next[len1]); i++)
                {
                    printf("%c",vis[i]);
                }
                printf("\n");
            }
            else*/
                printf("%s\n",vis);
        }
    }
    return 0;
}
