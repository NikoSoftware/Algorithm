#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std;

char s1[205],s2[205],goal[205],s3[500],count,n;
map<string,bool> s;

void moni()
{

    while(1)
    {
        count++;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            s3[cnt++]=s2[i];
            s3[cnt++]=s1[i];
        }
        if(strcmp(goal,s3)==0)
        {
            printf("%d",count);
            s.clear();
            return;
        }
        if(s[s3])
        {
            printf("%d",-1);
            s.clear();
            return;
        }
        s[s3]=true;
        for(int i=0; i<2*n; i++)
        {
            if(i<n)
            {
                s1[i]=s3[i];
            }
            else
                s2[i-n]=s3[i];
        }
    }
}
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        count=0;
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",goal);
        printf("%d ",i+1);
        moni();
        if(i!=k-1)
        printf("\n");
    }
    return 0;
}
