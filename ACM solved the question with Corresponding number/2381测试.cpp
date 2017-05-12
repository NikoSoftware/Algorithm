#include<stdio.h>
#include<string.h>
#include<math.h>
int a[100000000],count=1,c=0,head=0,d[200000];
int wide(int m)
{
    while(1)
    {
        a[count++]=a[head]+1;
        d[a[head]+1]=d[a[head]]+1;
        if(a[count-1]==m)
            return d[m];
        a[count++]=a[head]-1;
        d[a[head]-1]=d[a[head]]+1;
        if(a[count-1]==m)
            return d[m];
        if(a[head]<m)
        {
            a[count++]=a[head]*2;
            d[a[head]*2]=d[a[head]]+1;
            if(a[count-1]==m)
                return d[m];
        }

        head++;
    }
}
int main()
{
    int i,m,n,j,z;
    scanf("%d",&j);
    while(j--)
    {
        scanf("%d%d",&a[0],&m);
        memset(d,0,sizeof(d));
        count=1; head=0;
        z=wide(m);
        printf("%d\n",z);

    }
    return 0;
}
