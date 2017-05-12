//CODE: POJ_1703 652K	516MS
#include<stdio.h>
#include<iostream>
using namespace std;

int f[100010];

//����ڸ��ڵ������,true��ʾ��ͬ�false��ʾ����ͬ��
bool sex[100010];

//���ظ��ڵ㣬�Լ�����ڸ��ڵ������
int find(int x,bool &se)
{
	se=true;
	int r=x;
	while(x!=f[x])
	{
		if(sex[x]==false)
			se=!se;
		x=f[x];
	}
	//����������û��֮ǰ��ʱ,����֮��516MS��״̬ѹ��������
	f[r]=x;
	sex[r]=se;
	return x;
}
int main()
{
	int t,i,n,m,a,b,cnt=1;
	scanf("%d",&t);
	char str[3];
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			f[i]=i,sex[i]=true;
		bool judge=true;
		while(m--)
		{
			scanf("%s%d%d",str,&a,&b);
			bool l1=0,l2=0;
			//��ѯ��ǰ�ڵ�����ڸ��ڵ������
			int fa=find(a,l1),fb=find(b,l2);
			if(str[0]=='D')
			{
				//�ϲ���������
				f[fa]=fb;
				//���۲죬��2���ڵ�����ڸ��ڵ�����ʶ���true����falseʱ,�������ڵ㲻��ͬ���֮��ͬ��
				sex[fa]=l1^l2;
			}
			else
			{
				if(fa==fb)			//��ͬһ�����������ȷ���������˵��������
				{
					if(l1==l2)		//��ͬ��
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				}
				else				//����ͬһ���������޷�ȷ��
					printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}
