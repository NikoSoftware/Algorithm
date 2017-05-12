#include<cstdio>
#include<string.h>
using namespace std;

int x,y,z,a[10]= {0,1,2,3,4,5};
char c[100];


void unit(int f1,int n)
{
    if(f1==0)
        x=x+n;
    else if(f1==1)
        y=y+n;
    else if(f1==2)
        z=z+n;
    else if(f1==3)
        x=x-n;
    else if(f1==4)
        y=y-n;
    else
        z=z-n;

}
int main()
{
    int n,m,d;
    scanf("%d",&n);
    while(n--)
    {
        x=0;y=0;z=0;int face=0,left=4,up=2,temp;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%s%d",c,&d);
            if(c[0]=='f')
            {
                face=face;
            }
            else if(c[0]=='r')
                {
                  temp=face,face=(left+3)%6,left=temp;
                }
            else if(c[0]=='u')
                temp=face,face=up,up=(temp+3)%6;
            else if(c[0]=='b')
                face=(face+3)%6,left=(left+3)%6;
            else if(c[0]=='l')
                temp=face,face=left,left=(temp+3)%6;
            else
              temp=face,face=(up+3)%6,up=temp;
            unit(face,d);printf("%d %d %d %d\n",x,y,z,face);
        }

    }
    return 0;
}
