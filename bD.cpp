#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        printf("%.lf\n",pow(2,m-1));
    }
    return 0;
}
