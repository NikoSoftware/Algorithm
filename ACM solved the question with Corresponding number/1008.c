#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,n,index;
    while(scanf("%s",a)!=EOF)
    {
        index=0;
        if(a[0]=='0')
        continue;
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            index=(index*10+(a[i]-'0'))%17;
        }
        if(index==0)
        printf("%d\n",1);
        else
        printf("%d\n",0);
    }
}
