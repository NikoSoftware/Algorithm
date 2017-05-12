#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i,sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m>4)
        {
            printf("%.f\n",pow(2.0,m-1)-pow(2.0,m-3));
        }
        else
        if(m==4)
        printf("%d\n",7);
        else
        printf("%.f\n",pow(2.0,m-1));
    }
    return 0;
}
