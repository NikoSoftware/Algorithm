#include <stdio.h>
#include <string.h>
//#include <iostream>
#include <stdlib.h>

//using namespace std;

int v[150][150], step[12000];
int a, b, c, l, r;
char s[7][10] = {" ", "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(2,1)", "POUR(1,2)"};
struct node
{
    int x, y, d, front;//d是第几个，
} f[10500];
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
    /*int k=1;
    while(k!=l+1)
    {
        printf("%d %d %d %d k:%d\n",f[k].x,f[k].y,f[k].d,f[k].front,k);
        k++;
    }*/
    while(l!= 0)
    {
        step[t++] = f[l].d;
        l = f[l].front;
    }
    printf("%d\n",t);
    for(i = t-1; i >= 0; i--)
        printf("%s\n",s[step[i]]);
}
void bfs()
{
    f[0].x = 0,f[0].y = 0;
    v[0][0] = 1;
    l = 0, r = 1;
    while(l != r)
    {
        if(f[l].x == c || f[l].y == c)
        {
            _printf();
            return;
        }
        int xx, yy;//把1倒满
        xx = a;
        yy = f[l].y;
        slove(xx, yy, 1);

        xx = f[l].x;//把2倒满
        yy = b;
        slove(xx, yy, 2);

        xx = 0;//把1清空
        yy = f[l].y;
        slove(xx, yy, 3);

        xx = f[l].x;//把2清空
        yy = 0;
        slove(xx, yy, 4);

        xx = f[l].x + _min(a-f[l].x , f[l].y);//把2倒入1
        yy = f[l].y - _min(a-f[l].x , f[l].y);
        slove(xx, yy, 5);

        xx = f[l].x - _min(b-f[l].y , f[l].x);//把1倒入2
        yy = f[l].y + _min(b-f[l].y , f[l].x);
        slove(xx, yy, 6);

        l++;
    }
    if(l >= r)
        printf("impossible\n");
}
int main()
{
    scanf("%d %d %d",&a, &b, &c);
    memset(v , 0 , sizeof(v));
    bfs();
    return 0;
}
