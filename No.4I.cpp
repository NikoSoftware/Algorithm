#include<stdio.h>
#include<string.h>


int main()
{
    int s,d,data[20],sum;
    while(scanf("%d%d",&s,&d)!=EOF)
    {
        int count=0;
        for(int i=0; i<5; i++)
            data[i]=s;
        for(int i=4; i<12; i++)
        {
           // printf("%d,",i);
            data[i]=s;
            int cnt=i;
            sum=0;
            while(sum>=0)
            {

               // puts("fsaf");
                sum=0;
                for(int j=i-4; j<=i; j++)
                {
                   // printf("%d ",data[j]);
                    sum+=data[j];
                }
                //printf("sum=%d ",sum);
               // printf("\n");
                if(sum>0)
                data[cnt--]=-d;
            }
           // printf("\n");
        }
        for(int i=0; i<12; i++)
          {
              //printf("%d ",data[i]);
              count+=data[i];

          }
          if(count>0)
        printf("%d\n",count);
        else
        printf("Deficit\n");

    }


    return 0;
}
