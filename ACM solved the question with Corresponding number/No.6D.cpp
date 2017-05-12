#include<stdio.h>
#include<string.h>
char str[10][100],vis[100],map[100];
int next[100],ma,n,lenp;

void getnext()
{
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<lenp)
    {
        if(j==-1||map[i]==map[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}

void KMP()
{
    int k,m,i,j;
    getnext();
    ma=100;
    for(k=1; k<n; k++)
    {
        i = 0;
        j = 0;
        m = 0;
        while(i<60&&j<lenp)
        {
            if(j==-1||str[k][i]==map[j])
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
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int z=0; z<k; z++)
        {
            scanf("%d",&n);
            for(int i=0; i<n; i++)
            {
                scanf("%s",str[i]);
            }
            int ans=0;
            for(int i=0; i<57; i++)
            {
                strcpy(map,str[0]+i);
                lenp=60-i;
                KMP();
                if(ans < ma)
                {
                    ans = ma;
                    strncpy(vis, str[0] + i, ans);
                    vis[ans] = '\0';
                }
                else if(ans == ma)
                {
                    char tmp[100];
                    strncpy(tmp, str[0] + i, ans);
                    tmp[ans] = '\0';
                    if(strcmp(tmp, vis) < 0)
                        strcpy(vis, tmp);
                }

            }
            if(ans >= 3)
                printf("%s\n", vis);
            else
                printf("no significant commonalities\n");
        }
    }
    return 0;
}
