#include<stdio.h>
int main()
{
    int n,a[100],max,min,i;
    while(scanf("%d",&n)!=EOF)
    {
       if(n<=2||n>=100)
    return 0;
    else
    for(i=0;i<n;i++)
    {
   scanf("%d",&a[i]);
    }

       max=a[0];
       min=a[0];
       for(i=1;i<n;i++)
      {
          if(max<a[i])
       max=a[i];
       if(min>a[i])
       min=a[i];
      }
    int sum=0;
      for(i=0;i<n;i++)
      {
          sum+=a[i];
      }
      printf("%.2f\n",(sum-max-min)*1.00/(n-2));
    }
}
