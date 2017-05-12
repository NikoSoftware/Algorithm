#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000100];
    int next[1000100];
    int len,i,j;
    while(~scanf("%s",s))
    {
        if(s[0]=='.')break;
        int len=strlen(s);
        memset(next,0,sizeof(next));
        next[0]=-1;
        int i=0;
        int j=-1;
        while(i<len)
        {
            if(j==-1||s[i]==s[j])
                next[++i]=++j;
            else
                j=next[j];
        }
        if(len%(len-next[len])==0)
            printf("%d\n",len/(len-next[len]));
        else
            printf("1\n");
    }

}
