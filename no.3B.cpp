#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int data[500000];

int main()
{
    int n;
    scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&data[i]);
        }
        sort(data+1,data+n+1);
        if(n%2)
        printf("%.1f\n",data[(n+1)/2]*1.0);
        else
        printf("%.1f\n",data[n/2]/2.0+data[n/2+1]/2.0);
    return 0;
}
