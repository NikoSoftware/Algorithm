


/*void getNext(char *p,int *next)
{
    int j,k;
    next[0]=-1;
    j=0;
    k=-1;
    while(j<strlen(p)-1)
    {
        if(k==-1||p[j]==p[k])    //匹配的情况下,p[j]==p[k]
        {
            j++;
            k++;
            next[j]=k;
        }
        else                   //p[j]!=p[k]
            k=next[k];
    }
}*/


/*int  j = -1,  i = 0;
next[0] = -1;
while(i < len)
{
    if(j == -1 || ss[i] == ss[j])
    {

        i++;
        j++;
        next[i] = j;
    }
    else
    {
        j = next[j];
    }
}*/


#include<stdio.h>
#include<string.h>

int main()
{
    char data[40]= {"aabaabaabaab"};
    int len=strlen(data);
    int next[20];

    int  j = -1,  i = 0;
    next[0] = -1;
    while(i <= len)
    {
        if(j == -1 || data[i] == data[j])
        {

            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];

        }
    }
    printf(" ");
    for(int i=0; i<12; i++)
    {

        printf("%c ",data[i]);
    }
    puts("");
    puts("");
    for(int i=0; i<12; i++)
    {

        printf("%d ",next[i]);
    }

    return 0;
}
