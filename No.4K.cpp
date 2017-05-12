#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int data1[2000],data2[2000],score;

int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,cnt;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&data1[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&data2[i]);
        sort(data1,data1+n,cmp);
        sort(data2,data2+n,cmp);
        cnt=n-1;
        score=0;
        for(int i=0; i<n; i++)
        {
            puts("fsaf");
            if(data1[i-(n-cnt-1)]<=data2[i]||data1[cnt]==data2[n-1])
            {
                if(data1[i-(n-cnt-1)]==data2[i]&&data1[cnt]>data2[n-1])
                    score=score;
                else
                {
                    cnt--;
                    score-=200;
                }
            }
            else
               {
                  score+=200; data1[i]=-1;
               }
        }
        printf("%d\n",score);

    }
    return 0;
}
