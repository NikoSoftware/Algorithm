#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> a;//����һ��������

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            int val;
            scanf("%d",&val);
            a.push_back(val);//�ں���ѹ��һ����
        }
        for(int i=0; i<a.size(); i++)
        {
            printf("%d ",a[i]);
        }
        printf("Size %d\n",a.size());
        //a.clear();���
        a.pop_back();//ɾ��������һ��
        printf("Size %d\n",a.size());

    }
}



