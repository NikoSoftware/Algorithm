#include<stdio.h>
#include<algorithm>

using namespace std;

int data1[5000],data2[5000];

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,cnt,flag;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int score=0;
        for(int i=0; i<n; i++)
            scanf("%d",&data1[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&data2[i]);
        sort(data1,data1+n,cmp);
        sort(data2,data2+n,cmp);
        cnt=n-1;
       int z=n-1;
          int j=0;
          int i=0;
          int m=0;
        while(1)
        {
            if(m==n)
            break;
            if(data1[i]<data2[j])
            {
                cnt--;
                j++;
                m++;
                score-=200;
            }
            else if(data1[i]==data2[j])
            {
                if(data1[cnt]>data2[z])
                {
                    cnt--;
                    z--;
                    m=m++;
                    score+=200;
                }
                else if(data1[cnt]<data2[j])
                {
                    cnt--;
                    j++;
                    m++;
                    score-=200;
                }
                else
                {
                    j++;
                    cnt--;
                    m++;
                }

            }
            else
                {
                    score+=200;
                    j++;
                    i++;
                    m++;
                }
        }printf("%d\n",score);
    }
    return 0;
}
