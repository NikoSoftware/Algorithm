#include<stdio.h>
#include<string.h>

int main()
{
    char b[200000];
    int temp,next[200000];
    while(scanf("%s",b)!=EOF)
    {
        if(b[0]=='.')
            break;
        int bn=strlen(b);
        memset(next, 0, sizeof(next));
        for(int i = 1; i < bn; i++)
        {
            temp = next[i - 1];
            while(temp && b[temp] != b[i])
                temp = next[temp - 1];
            if(b[temp] == b[i])
                next[i] = temp + 1;
            else
                next[i] = 0;
        }
        if(bn%(bn-next[bn-1])==0)
            printf("%d\n",bn/(bn-next[bn-1]));
        else
            printf("1\n");


    }

}
