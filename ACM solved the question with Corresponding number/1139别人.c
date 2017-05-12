#include<stdio.h>
struct p
{
    int m, d, y;
    int sum;
}d[1024],temp;
void Bubble_Sort(int cot)
{
    int i,j;

    for(i=0;i<cot;i++)
    {
        for(j=0;i+j<cot-1;j++)
        {
            if(d[j].sum<d[j+1].sum)
            {
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
            }
        }
    }
}
int main()
{
    int cot=0;
    while(scanf("%d/%d/%d",&d[cot].m,&d[cot].d,&d[cot].y)!=EOF)
    {
        cot++;
        d[cot].sum=d[cot].y*10000+d[cot].m*100+d[cot].d;
    }
    Bubble_Sort(cot);
    for(int i=0;i<cot;i++)
    {
        printf("%02d/%02d/%04d\n",d[i].m,d[i].d,d[i].y);
    }

}
