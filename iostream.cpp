#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int val= __gcd(a,b);//���Լ����
        printf("%d\n",val);
       swap(a,b);//����a,b,��ֵ��
       printf("%d %d\n",a,b);


    }
    return 0;
}
