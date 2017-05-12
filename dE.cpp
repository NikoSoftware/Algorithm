//此方法超时
#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,a[1000];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        int count=0,top=1,first=0,temp;
        memset(a,0,sizeof(a));
        scanf("%d",&a[0]);
        while(a[first]!=0)
        {
        temp=a[first]-1;
        if(temp>=0)
        {
            if(temp==0)
            count++;
            else
            a[top++]=temp;
        }
        temp=a[first]-2;
        if(temp>=0)
        {
            if(temp==0)
            count++;
            else
            a[top++]=temp;
        }
        temp=a[first]-3;
        if(temp>=0)
        {
            if(temp==0)
            count++;
            else
            a[top++]=temp;
        }
        first++;
        }
        printf("%d\n",count);
    }
    return 0;
}
