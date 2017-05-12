#include<stdio.h>
#include<string.h>
#include<math.h>
int a[100000000],count=1,c=0,head=0;
double h=0;
void wide(int m)
{
    while(head<=count)
    {
    c++;
    int i;
   if(a[head]==m)
   {
       h=log(c+1)/log(3.0);
       return ;
   }
   a[count++]=a[head]+1;
   a[count++]=a[head]-1;
   a[count++]=a[head++]*2;
    }
}
int main()
{
    int i,m,n,j,z;
    scanf("%d",&j);
    while(j--)
    {
        scanf("%d%d",&a[0],&m);
        wide(m);
        printf("%d\n",(int)h);

    }
    return 0;
}
