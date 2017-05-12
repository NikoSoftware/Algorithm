#include<stdio.h>
#include<string.h>
#include<math.h>
void quicksort(long long *a,int low,int high)
{
    int i=low,j=high;
    if(low<high)
    {
        long long mid=a[i];
        while(i<j)
        {
            while(i<j&&mid<=a[j])
                j--;
            a[i]=a[j];
            while(i<j&&mid>=a[i])
                i++;
            a[j]=a[i];
        }
        a[i]=mid;
        quicksort(a,low,i-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int k,n,m,i;
    long long sum,a[100000],b[10000],c[1000],d;
    char vis[100000];
    scanf("%d",&k);
    int v=k;
    while(k--)
    {
        sum=0;
        scanf("%s",vis);
        n=strlen(vis);
        int cnt1=0,cnt2=0;
        d=1;
        for(i=0; i<n; i++)
        {
            if(vis[i]=='-')
            {
                d=-1;
            }
            else
            if(vis[i]>='0'&&vis[i]<='9')
            {
                sum=sum*10+(vis[i]-'0');
                //printf("cont=%d sum=%d ",cont-1,sum);

            }
            else
            if(vis[i]==','&&sum!=0)
            {
                a[cnt1++]=sum*d;
                sum=0;
                d=1;
            }
            else
            if(vis[i]=='}')
            {
                a[cnt1]=sum*d;
                sum=0;
                d=1;
            }
        }



        scanf("%s",vis);
        m=strlen(vis);
        for(i=0; i<m; i++)
        {
            if(vis[i]=='-')
            d=-1;
            if(vis[i]>='0'&&vis[i]<='9')
            {
                sum=sum*10+(vis[i]-'0');
            }
            if(vis[i]==','&&sum!=0)
            {
                b[cnt2++]=sum*d;
                sum=0;
                d=1;
            }
            if(vis[i]=='}'&&(vis[i-1]!=','))
            {
                b[cnt2]=sum*d;
            }
        }
        for(i=0;i<=cnt2;i++)
        printf("~%lld~",b[i]);
        printf("\n");

        int cnt3=0,j;
        int z=cnt1;
        for(i=0; i<=cnt2; i++)
        {
            int flag=0;
            for(j=0; j<=z; j++)
            {
                if(b[i]==a[j])
                {
                    c[cnt3++]=b[i];
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                a[++cnt1]=b[i];
            }
        }
        quicksort(a,0,cnt1);
        quicksort(c,0,cnt3-1);
        printf("Case #%d:\n{",v-k);
        for(i=0; i<cnt3-1; i++)
        {
            printf("%lld,",c[i]);
        }
        if(cnt3!=0)
            printf("%lld}\n",c[cnt3-1]);
        else
            printf("}\n");
        printf("{");
        for(i=0; i<cnt1; i++)
        {
            printf("%lld,",a[i]);
        }
        printf("%lld}\n",a[cnt1]);
    }
    return 0;
}
