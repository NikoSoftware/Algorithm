#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int val= __gcd(a,b);//最大公约数；
        printf("%d\n",val);
       swap(a,b);//交换a,b,的值；
       printf("%d %d\n",a,b);


    }
    return 0;
}
