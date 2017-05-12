#include<stdio.h>
long data[21][21][21] = {0};
int fun(int a,int b,int c)
{

    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
        return fun(20,20,20);
    if(data[a][b][c])
        return data[a][b][c];
    else if(a<b&&b<c)
        return fun(a, b, c-1) + fun(a, b-1, c-1) - fun(a, b-1, c);
    else
        return fun(a-1, b, c) + fun(a-1, b-1, c) + fun(a-1, b, c-1) - fun(a-1, b-1, c-1);
}


int main()
{
    int a, b ,c;
    data[0][0][0] = 1;
    for(a = 0; a<=20; a++)
        for(b = 0; b<=20; b++)
            for(c = 0; c <=20; c ++)
            {
                data[a][b][c] = fun(a,b,c);
            }
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a==-1&&b==-1&&c==-1)
            return 1;
        printf("w(%d, %d, %d) = %d\n",a,b,c,fun(a,b,c));
    }
    return 0;
}
