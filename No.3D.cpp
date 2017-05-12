#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int cnt=0,cnt1=0,cnt2=0,cnt3=0;
char map[1000];
struct Point
{
    int x,y,cl;

} pointw[1000],pointb[1000];

char p(int b)
{
    switch(b)
    {
    case 1:
        return 'k';
    case 2:
        return 'Q';
    case 3:
        return 'R';
    case 4:
        return 'B';
    case 5:
        return 'N';
    case 6:
        return 's';
    }
}


int cmp(struct Point a,struct Point b)
{
    if(a.cl==b.cl)
    {
        if(a.x==b.x)
            return a.y<b.y;
        else
            return a.x>b.x;
    }

    return a.cl<b.cl;
}
int cmp2(struct Point a,struct Point b)
{
    if(a.cl==b.cl)
    {
        if(a.x==b.x)
            return a.y<b.y;
        else
            return a.x<b.x;
    }
    return a.cl<b.cl;
}

int main()
{
    int m=0,cnt=0,n;
    for(int i=1; i<18; i++)
    {
        scanf("%s",map);
        if(map[1]=='-')
            continue;
        m++;
        n=strlen(map);
        for(int j=2; j<n; j+=4)
        {
            switch(map[j])
            {
            case 'K':
                pointw[cnt].x=9-m;
                pointw[cnt].y=(j+2)/4;
                pointw[cnt++].cl=1;
                break;
            case 'Q':
                pointw[cnt].x=9-m;
                pointw[cnt].y=(j+2)/4;
                pointw[cnt++].cl=2;
                break;
            case 'R':
                pointw[cnt].x=9-m;
                pointw[cnt].y=(j+2)/4;
                pointw[cnt++].cl=3;
                break;
            case 'B':
                pointw[cnt].x=9-m;
                pointw[cnt].y=(j+2)/4;
                pointw[cnt++].cl=4;
                break;
            case 'N':
                pointw[cnt].x=9-m;
                pointw[cnt].y=(j+2)/4;
                pointw[cnt++].cl=5;
                break;
            case 'P':
                pointw[cnt].x=9-m;
                pointw[cnt].y=(j+2)/4;
                pointw[cnt++].cl=6;
                cnt2++;
                break;
            case 'p':
                pointb[cnt1].x=9-m;
                pointb[cnt1].y=(j+2)/4;
                pointb[cnt1++].cl=6;
                cnt3++;
                break;
            case 'k':
                pointb[cnt1].x=9-m;
                pointb[cnt1].y=(j+2)/4;
                pointb[cnt1++].cl=1;
                break;
            case 'q':
                pointb[cnt1].x=9-m;
                pointb[cnt1].y=(j+2)/4;
                pointb[cnt1++].cl=2;
                break;
            case 'r':
                pointb[cnt1].x=9-m;
                pointb[cnt1].y=(j+2)/4;
                pointb[cnt1++].cl=3;
                break;
            case 'b':
                pointb[cnt1].x=9-m;
                pointb[cnt1].y=(j+2)/4;
                pointb[cnt1++].cl=4;
                break;
            case 'n':
                pointb[cnt1].x=9-m;
                pointb[cnt1].y=(j+2)/4;
                pointb[cnt1++].cl=5;
                break;
            }
        }
    }
    sort(pointw,pointw+cnt,cmp2);
    sort(pointb,pointb+cnt1,cmp);

    printf("White: ");
    for(int i=0; i<cnt; i++)
    {
        if(pointw[i].cl!=6)
            printf("%c%c%d,",p(pointw[i].cl),pointw[i].y+'a'-1,pointw[i].x);
        else if(i==cnt-1)
            printf("%c%d",pointw[i].y+'a'-1,pointw[i].x);
        else
            printf("%c%d,",pointw[i].y+'a'-1,pointw[i].x);
    }
    printf("\nBlack: ");
    for(int i=0; i<cnt1; i++)
    {
        if(pointb[i].cl!=6)
            printf("%c%c%d,",p(pointb[i].cl),pointb[i].y+'a'-1,pointb[i].x);
        else
        {
            if(i==cnt-1)
                printf("%c%d",pointb[i].y+'a'-1,pointb[i].x);
            else
                printf("%c%d,",pointb[i].y+'a'-1,pointb[i].x);
        }
    }
    printf("\n");
}
