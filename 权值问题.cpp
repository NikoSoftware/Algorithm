//CODE: POJ_1703 652K	516MS
#include<stdio.h>
#include<iostream>
using namespace std;

int f[100010];

//相对于父节点的性质,true表示是同伙，false表示不是同伙
bool sex[100010];

//返回父节点，以及相对于父节点的性质
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
	//以下这两句没加之前超时,加了之后516MS，状态压缩的作用
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
			//查询当前节点相对于父节点的性质
			int fa=find(a,l1),fb=find(b,l2);
			if(str[0]=='D')
			{
				//合并两个集合
				f[fa]=fb;
				//经观察，当2个节点相对于父节点的性质都是true或都是false时,两个父节点不是同伙，反之是同伙
				sex[fa]=l1^l2;
			}
			else
			{
				if(fa==fb)			//在同一个集合里就能确定两个犯人的相对属性
				{
					if(l1==l2)		//是同伙
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				}
				else				//不在同一个集合里无法确定
					printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}
