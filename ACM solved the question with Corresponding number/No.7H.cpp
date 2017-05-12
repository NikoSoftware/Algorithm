#include<stdio.h>
#include<string.h>
char data[1000000];
int next[1000000],n;

void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<n)
    {
        if(j==-1||data[i]==data[j])
        {
            i++;
            j++;
            if(i%(i-j)==0&&(i/(i-j)>1))
            printf("%d %d\n",i,i/(i-j));
            next[i]=j;
        }
        else
        j=next[j];
    }
}


int main()
{
    int k=0;

    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        k++;
        scanf("%s",data);
        printf("Test case #%d\n",k);
        getnext();
         printf("\n");
    }
    return 0;
}
