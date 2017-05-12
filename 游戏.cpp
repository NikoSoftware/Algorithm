
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include <windows.h>

int v[100][100], step[5000];
int a, b, c, l, r,a1,b1,tem;
char s[7][50] = {" ", "将A杯子装满", "将B杯子装满", "将A杯子清空", "将B杯子清空", "将B杯子的水倒入A杯子", "将A杯子的水倒入B杯子"};
char s1[10][150]= {"","游戏说明","有两个没有刻度的水杯,A,B,通过下面几步操作以最少的操作次数实现以下操作：","1.将A杯子装满","2.将B杯子装满","3.将A杯子清空","4.将B杯子清空","5.将B倒入A","6.将A倒入B"};

struct node
{
    int x, y, d, front;
} f[1050];

void Pos(short x,short y)//设置光标位置函数
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
    return;
}//Pos

int _min(int xx, int yy)
{
    if(xx > yy)
        return yy;
    return xx;
}
void slove(int xx, int yy, int ss)
{
    if(v[xx][yy])
        return;
    v[xx][yy] = 1;
    f[r].x = xx, f[r].y = yy, f[r].d = ss, f[r++].front = l;
}
void _printf()
{
    int i, t = 0;
    while(l!= 0)
    {
        step[t++] = f[l].d;
        l = f[l].front;
    }
    Pos(30,14);
    printf("操作步数：%d\n",t);
    for(i = t-1; i >= 0; i--)
    {
        Pos(30,15+t-i);
        printf("%s\n\n",s1[step[i]+2]);
    }
}
int bfs()
{
    f[0].x = 0,f[0].y = 0;
    v[0][0] = 1;
    l = 0, r = 1;
    while(l != r)
    {
        if(f[l].x == c || f[l].y == c)
        {
            if(l==0)
                return 1;

            return 0;
        }
        int xx, yy;
        xx = a;
        yy = f[l].y;
        slove(xx, yy, 1);

        xx = f[l].x;
        yy = b;
        slove(xx, yy, 2);

        xx = 0;
        yy = f[l].y;
        slove(xx, yy, 3);

        xx = f[l].x;
        yy = 0;
        slove(xx, yy, 4);

        xx = f[l].x + _min(a-f[l].x , f[l].y);
        yy = f[l].y - _min(a-f[l].x , f[l].y);
        slove(xx, yy, 5);

        xx = f[l].x - _min(b-f[l].y , f[l].x);
        yy = f[l].y + _min(b-f[l].y , f[l].x);
        slove(xx, yy, 6);

        l++;
        if(l >= r||l>15)
            return 1;

    }

}

void moving(char *a)
{
    int n=strlen(a);
    for(int i=0; i<n; i++)
    {
        printf("%c",a[i]);
        Sleep(50);
    }
}

void image()
{
    Pos(30,2);
    moving(s1[1]);
    Pos(7,5);
    moving(s1[2]);
    Pos(25,7);
    moving(s1[3]);
    Pos(25,8);
    moving(s1[4]);
    Pos(25,10);
    moving(s1[5]);
    Pos(25,11);
    moving(s1[6]);
    Pos(25,13);
    moving(s1[7]);
    Pos(25,14);
    moving(s1[8]);
    Pos(25,17);
    printf("任意键开始…………");
    getchar();
    system("cls");
}

void remain(int t)
{
    switch(t)
    {
    case 1:
        a1=a;
        break;
    case 2:
        b1=b;
        break;
    case 3:
        a1=0;
        break;
    case 4:
        b1=0;
        break;
    case 5:
     tem=a1;
        a1=a1+_min(a-a1,b1);
        b1=b1-_min(a-tem,b1);
        break;
    case 6:
    tem=a1;
        a1=a1-_min(b-b1,a1);
        b1=b1+_min(b-b1,tem);
        break;
    }
}


int main()
{
    int get[100],step1[100];
    image();
    while(1)
    {
        system("cls");
        int k=1,o=1;
        while(k)
        {
            srand((int)time(NULL));

            a=rand()%15;
            while(a==0)
                a=rand()%15;
            b=rand()%15;
            while(a==b||b==0)
            {
                b=rand()%15;
            }
            c=rand()%15;
            while(c>=a&&c>=b||c==1)
            {
                c=rand()%15;
            }
            memset(v , 0 , sizeof(v));
            Pos(30,10);
            printf("waiting…………");
            k=bfs();
        }



        int z=0;
        k=l;
        while(k!=0)
        {
            step1[z++] = f[k].d;
            k = f[k].front;
        }
        /*printf("答案:");
        for(int i=z-1; i>=0; i--)
            printf("%d ",step1[i]);*/
        while(1)
        {
            system("cls");
            int flag=0;
            Pos(1,1);
            char m1[150]= {"1.将A杯子装满 2.将B杯子装满 3.将A杯子清空 4.将B杯子清空 5.将B倒入A 6.将A倒入B"};
            moving(m1);
            Pos(30,3);
            printf("A杯子：%d",a);
            Pos(30,4);
            printf("B杯子：%d",b);
            Pos(30,6);
            printf("任务杯子余水量：%d",c);
            a1=0,b1=0;

            Pos(2,3);
            printf("杯子剩余量：");
            Pos(15,3);
            printf("A杯子：%d",a1);
            Pos(15,4);
            printf("B杯子：%d",b1);


            Pos(30,7);
            printf("请输入操作步骤%d:",z);
            for(int i=0; i<z; i++)
            {
                Pos(0,8+i*2);
                scanf("%d",&get[i]);
                printf("%s\n",s[get[i]]);
                remain(get[i]);

                Pos(15,3);
                printf("A杯子：%d ",a1);
                Pos(15,4);
                printf("B杯子：%d ",b1);


            }

            for(int i=0; i<z; i++)
            {
                if(get[i]!=step1[z-i-1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                Pos(40,10);
                printf("对不起，解答错误。");
                Pos(40,11);
                printf("如需解答过程请输入1");
                Pos(40,12);
                getchar();
                if(getchar()=='1')
                {
                    _printf();
                    getchar();
                    break;
                }
            }
            else
            {
                Pos(40,10);
                printf("解答正确请继续加油！");
                getchar();
                break;
            }
        }
        getchar();
    }
    return 0;
}
