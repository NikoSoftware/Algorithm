#include<stdio.h>
int main()
{
    char s;
    int i,num[30]={0};


        while(scanf("%c",&s))
        {


        if(s=='#')
        {
            break;
        }
        if(s>='a'&&s<='z')
        {
            num[s-'a']++;
        }
        }

    for(i=0;i<26;i++)
    {
        printf("%c %d\n",i+'a',num[i]);
    }
    return 0;
}
