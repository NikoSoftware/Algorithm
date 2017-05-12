#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> a;//定义一个容器；

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            int val;
            scanf("%d",&val);
            a.push_back(val);//在后面压入一个数
        }
        for(int i=0; i<a.size(); i++)
        {
            printf("%d ",a[i]);
        }
        printf("Size %d\n",a.size());
        //a.clear();清空
        a.pop_back();//删除最后面的一个
        printf("Size %d\n",a.size());

    }
}



